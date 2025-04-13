class Solution
{
private:
    void updateDist(int node, vector<vector<int>> &nextNodes, vector<int> &dist, int &update_dist)
    {
        dist[node] += update_dist;
        for (auto nextNode : nextNodes[node])
        {
            updateDist(nextNode, nextNodes, dist, update_dist);
        }
    }

public:
    vector<int> treeQueries(int n, vector<vector<int>> &edges, vector<vector<int>> &queries)
    {
        // dijkstra's algo
        vector<unordered_map<int, int>> adj(n + 1);
        vector<vector<int>> nextNode(n + 1);
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u][v] = wt;
            nextNode[u].push_back(v);
        }
        vector<int> dist(n + 1, 1e9);
        dist[1] = 0;
        priority_queue<pair<int, int>> pq;
        pq.push({0, 1});
        while (!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();
            int d = temp.first;
            int node = temp.second;
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int wt = it.second;
                if (d + wt < dist[adjNode])
                {
                    dist[adjNode] = d + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        // run queries;
        vector<int> ans;
        for (auto query : queries)
        {
            if (query[0] == 2)
            {
                int x = query[1];
                ans.push_back(dist[x]);
            }
            else
            {
                int u = query[1];
                int v = query[2];
                int w_ = query[3];
                int update_dist = w_ - adj[u][v];
                adj[u][v] = w_;
                // for(auto &it:adj[u]){ // optimize this
                //     if(it.first==v){
                //         update_dist=w_-it.second;
                //         it.second=w_;
                //         break;
                //     }
                // }
                updateDist(v, nextNode, dist, update_dist);
            }
        }
        return ans;
    }
};