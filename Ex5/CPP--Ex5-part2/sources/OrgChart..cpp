#include "OrgChart.hpp"
using namespace std;
namespace ariel
{
    /**
     * @brief Construct a new Org Chart:: Org Chart object
     * and init him to be empty
     */
    OrgChart::OrgChart()
    {
        root.name = "empty";
    }
    /**
     * @brief Add a root to the tree
     * if the root already exists the function replace him
     *
     * @param name
     * @return OrgChart&
     */
    OrgChart &OrgChart::add_root(string name)
    {
        if (name.empty())
        {
            throw runtime_error("the name of the root can not be empty");
        }
        
        root.name = move(name);
        return *this;
    }
    /**
     * @brief Add a new son to the dad in the tree with the other function
     *
     * @param dad
     * @param son
     * @return OrgChart&
     */
    OrgChart &OrgChart::add_sub(string dad, string son)
    {
        if (son.empty())
        {
            throw runtime_error("the name of the son can not be empty");
        }
        if (!add_sub(root, dad, son))
        {
            throw runtime_error(dad + " does not exist in the organization");
        }
        return *this;
    }
    /**
     * @brief Looking for the father in the tree and adding the child
     *
     * @param node
     * @param dad
     * @param son
     * @return true
     * @return false
     */
    bool OrgChart::add_sub(Node &node, string &dad, string &son)
    {
        if (node.name == dad)
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
    /**
     * @brief Returns true if the tree is empty
     *
     * @return true
     * @return false
     */
    bool OrgChart::empty() const
    {
        return (root.name == "empty");
    }
    /**
     * @brief Fill the vector iter_level_order in the right order with fill_level_order
     * return pointer to the name in place [0]
     * @return string*
     */
    string *OrgChart::begin_level_order()
    {
        if (empty())
        {
            throw runtime_error("chart is empty!");
        }
        iter_level_order.clear();
        fill_level_order();
        return &iter_level_order[0];
    }
    /**
     * @brief Fill the iter_level_order vector with BFS
     *
     */
    void OrgChart::fill_level_order()
    {
        vector<Node *> tempQueue;
        tempQueue.push_back(&root);
        for (size_t i = 0; i < tempQueue.size(); i++)
        {
            Node *tempNode = tempQueue[i];
            iter_level_order.push_back(tempNode->name);
            for (size_t j = 0; j < tempNode->sones.size(); j++)
            {
                tempQueue.push_back(&(tempNode->sones[j]));
            }
        }
    }
    /**
     * @brief Return pointer to the last name in iter_level_order
     *
     * @return string*
     */
    string *OrgChart::end_level_order()
    {
        if (empty())
        {
            throw runtime_error("chart is empty!");
        }
        return &iter_level_order[iter_level_order.size()];
    }
    /**
     * @brief Fill the vector iter_reverse_order in the right order with fill_reverse_order
     * return pointer to the name in place [0]
     * @return string*
     */
    string *OrgChart::begin_reverse_order()
    {
        if (empty())
        {
            throw runtime_error("chart is empty!");
        }
        iter_reverse_order.clear();
        fill_reverse_order();
        return &iter_reverse_order[0];
    }
    /**
     * @brief Fill the iter_reverse_order vector with revers BFS
     *
     */
    void OrgChart::fill_reverse_order()
    {
        vector<Node *> tempQueue;
        tempQueue.push_back(&root);
        for (size_t i = 0; i < tempQueue.size(); i++)
        {
            Node *tempNode = tempQueue[i];
            for (int j = (int)tempNode->sones.size() - 1; j >= 0; j--)
            {
                tempQueue.push_back(&(tempNode->sones[(size_t)j]));
            }
        }
        for (int i = (int)tempQueue.size() - 1; i >= 0; i--)
        {
            string newName = tempQueue[(size_t)i]->name;
            iter_reverse_order.push_back(newName);
        }
    }
    /**
     * @brief Return pointer to the last name in iter_reverse_order
     *
     * @return string*
     */
    string *OrgChart::reverse_order()
    {
        if (empty())
        {
            throw runtime_error("chart is empty!");
        }
        return &iter_reverse_order[iter_reverse_order.size()];
    }
    /**
     * @brief Fill the vector iter_preorder in the right order with fill_preorder
     * return pointer to the name in place [0]
     * @return string*
     */
    string *OrgChart::begin_preorder()
    {
        if (empty())
        {
            throw runtime_error("chart is empty!");
        }
        iter_preorder.clear();
        fill_preorder(root);
        return &iter_preorder[0];
    }
    /**
     * @brief Fill the fill_preorder vector with recursive transition
     *
     */
    void OrgChart::fill_preorder(Node &node)
    {
        iter_preorder.push_back(node.name);
        for (size_t i = 0; i < node.sones.size(); i++)
        {
            fill_preorder(node.sones[i]);
        }
    }
    /**
     * @brief Return pointer to the last name in iter_preorder
     *
     * @return string*
     */
    string *OrgChart::end_preorder()
    {
        if (empty())
        {
            throw runtime_error("chart is empty!");
        }
        return &iter_preorder[iter_preorder.size()];
    }
    /**
     * @brief Print the tree in level_order
     *
     * @param os
     * @param org
     * @return ostream&
     */
    ostream &operator<<(ostream &os, OrgChart &org)
    {
        for (auto *it = org.begin_iter_print(); it != org.end_iter_print(); ++it)
        {
            os << (*it);
        }
        return os;
    }

    /**
     * @brief Make a new string* iterator for print the tree
     * I got help from Dvir Biton and from
     * https://andrewlock.net/creating-an-ascii-art-tree-in-csharp/
     * @return string* 
     */
    string *OrgChart::begin_iter_print()
    {
        iter_print.clear();
        fill_iter_print(root, "", true);
        return &iter_print[0];
    }
    void OrgChart::fill_iter_print(Node &node, string str, bool isLast)
    {
        iter_print.push_back(str);
        if (isLast)
        {
            iter_print.push_back(" └─>");
            str += "   ";
        }
        else
        {
            iter_print.push_back(" ├─>");
            str += " │ ";
        }
        iter_print.push_back(node.name + "\n");
        for (size_t i = 0; i < node.sones.size(); i++)
        {
            bool j = (i == node.sones.size() - 1);
            fill_iter_print(node.sones.at(i), str, j);
        }
    }
    string *OrgChart::end_iter_print()
    {
        return &iter_print[iter_print.size()];
    }
}