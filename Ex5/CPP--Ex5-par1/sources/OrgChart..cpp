#include "OrgChart.hpp"
using namespace std;
namespace ariel
{
    OrgChart &OrgChart::add_root(string name)
    {
        root.name = name;
        return *this;
    }
    OrgChart &OrgChart::add_sub(string dad, string son)
    {
        if (!add_sub(root, dad, son))
        {
            throw runtime_error(dad + " does not exist in the organization");
        }
        return *this;
    }
    bool OrgChart::add_sub(Node &node, string &dad, string &son)
    {
        if (!node.name.compare(dad))
        {
            Node temp;
            temp.name = son;
            node.sones.push_back(temp);
            return true;
        }
        for (size_t i = 0; i < node.sones.size(); i++)
        {
            if (add_sub(node.sones[i], dad, son))
            {
                return true;
            }
        }
        return false;
    }
    string *OrgChart::begin_level_order()
    {
        iter_level_order.clear();
        fill_level_order();
        return &iter_level_order[0];
    }
    void OrgChart::fill_level_order()
    {
        vector<Node*> tempQueue;
        tempQueue.push_back(&root);
        for (size_t i = 0; i < tempQueue.size(); i++)
        {
            Node* tempNode = tempQueue[i];
            iter_level_order.push_back(tempNode->name);
            for (size_t j = 0; j < tempNode->sones.size(); j++)
            {
                tempQueue.push_back(&(tempNode->sones[j]));
            }
        }
    }
    string *OrgChart::end_level_order()
    {
        return &iter_level_order[iter_level_order.size()];
    }

    string *OrgChart::begin_reverse_order()
    {
        iter_reverse_order.clear();
        fill_reverse_order();
        return &iter_reverse_order[0];
    }
    void OrgChart::fill_reverse_order()
    {
        vector<Node*> tempQueue;
        tempQueue.push_back(&root);
        for (size_t i = 0; i < tempQueue.size(); i++)
        {
            Node* tempNode = tempQueue[i];
            for (int j = tempNode->sones.size()-1; j >= 0; j--)
            {
                tempQueue.push_back(&(tempNode->sones[(size_t)j]));
            }
        }
        for (int i = tempQueue.size()-1; i >= 0; i--)
        {
            string newName = tempQueue[(size_t)i]->name;
            iter_reverse_order.push_back(newName);
        }
        
    }
    string *OrgChart::reverse_order()
    {
        return &iter_reverse_order[iter_reverse_order.size()];
    }

    string *OrgChart::begin_preorder()
    {
        iter_preorder.clear();
        fill_preorder(root);
        return &iter_preorder[0];
    }
    void OrgChart::fill_preorder(Node &node)
    {
        iter_preorder.push_back(node.name);
        for (size_t i = 0; i < node.sones.size(); i++)
        {
            fill_preorder(node.sones[i]);
        }
    }
    string *OrgChart::end_preorder()
    {
        return &iter_preorder[iter_preorder.size()];
    }
    ostream &operator<<(ostream &os, OrgChart &org)
    {
        for (auto it = org.begin_level_order(); it != org.end_level_order(); ++it)
        {
            os << (*it) << ", ";
        }
        return os;
    }
}