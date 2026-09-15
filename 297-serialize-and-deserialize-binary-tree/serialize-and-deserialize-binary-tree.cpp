class Codec {
public:

    vector<string> split(string str) {
        vector<string> ans;
        string s = "";

        for (int i = 0; i < str.size(); i++) {

            if (str[i] == ',') {
                ans.push_back(s);
                s = "";
            }
            else {
                s += str[i];
            }
        }

        ans.push_back(s);

        return ans;
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if (!root)
            return "";

        vector<string> S;
        string ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* temp = q.front();
            q.pop();

            if (!temp) {
                S.push_back("#");
                continue;
            }

            S.push_back(to_string(temp->val));

            q.push(temp->left);
            q.push(temp->right);
        }


        // Convert vector to string
        for (int i = 0; i < S.size(); i++) {

            ans += S[i];

            if (i < S.size() - 1)
                ans += ',';
        }

        return ans;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if (data.empty())
            return NULL;

        vector<string> newData = split(data);

        TreeNode* root =
            new TreeNode(stoi(newData[0]));

        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < newData.size()) {

            TreeNode* parent = q.front();
            q.pop();


            // Left child
            if (i < newData.size() &&
                newData[i] != "#") {

                parent->left =
                    new TreeNode(stoi(newData[i]));
            }

            i++;


            // Right child
            if (i < newData.size() &&
                newData[i] != "#") {

                parent->right =
                    new TreeNode(stoi(newData[i]));
            }

            i++;


            // Push children
            if (parent->left)
                q.push(parent->left);

            if (parent->right)
                q.push(parent->right);
        }

        return root;
    }
};