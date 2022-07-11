#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;
namespace ariel
{
    struct Node
    {
        string name;
        vector<Node> sones;
    };
    class OrgChart
    {
    private:
        Node root;
        bool add_sub(Node &node, string &dad, string &son);
        vector<string> iter_level_order;
        void fill_level_order();
        vector<string> iter_reverse_order;
        void fill_reverse_order();
        vector<string> iter_preorder;
        void fill_preorder(Node &node);

    public:
        // OrgChart();
        OrgChart &add_root(string name);
        OrgChart &add_sub(string dad, string son);

        string *begin_level_order();
        string *end_level_order();

        string *begin_reverse_order();
        string *reverse_order();

        string *begin_preorder();
        string *end_preorder();

        string *begin(){return begin_level_order();}
        string *end(){return end_level_order();}
        // ~OrgChart();
        friend ostream &operator<<(ostream &os, OrgChart &root);
    };
}