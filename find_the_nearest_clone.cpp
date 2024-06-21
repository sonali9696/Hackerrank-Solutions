#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */
int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    
    vector<int> reqColorNode;
    for(int i = 1; i <= graph_nodes; i++)
    {
        if(ids[i-1] == val)
        {
            reqColorNode.push_back(i);
        }
    }
    
    //create adjacency list
    int n = graph_from.size();
    map<int, vector<int>> adj;
    for(int i=0; i<n; i++)
    {
        adj[graph_from[i]].push_back(graph_to[i]);
        adj[graph_to[i]].push_back(graph_from[i]);
    }
    
    //bfs of every node of required colour
    n = reqColorNode.size();
    int ans = INT_MAX;
    
    for(int i=0; i<n; i++)
    {
        int currNode = reqColorNode[i];
        cout<<"bfs of "<<currNode<<endl;
        
        // bfs from here
        int level = 0;
        queue<pair<int, int> > q;
        vector<bool> visited(graph_nodes+1, false);
        q.push(make_pair(currNode, 0));
        visited[currNode] = true;
        while(!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            int u = p.first, level = p.second;
            cout<<"popping "<<u<<endl;
            if(ids[u-1] == val && u != currNode) 
            {
                cout<<"found "<<u<<"at level "<<level<<endl;
                ans = min(ans, level);
                break;
            }
            
            for(auto node : adj[u]) //neighbours
            {
                if(visited[node]) continue;
                cout<<"pushing "<<node<<endl;
                q.push(make_pair(node, level+1));
                visited[node] = true;
            }
        }
    }
    
    if(ans == INT_MAX) return -1;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
