/*********************************
 * Operation #1: Increment the elements within range [u, v] with value val
 * Operation #2: Get max element within range [u, v]
 * Build tree: build_tree(1, 1, n)
 * Update tree: update_tree(1, 1, n, u, v, val)
 * Query tree: query_tree(1, 1, n, u, v)
 *********************************/

int n, q;
long long a[MN], nodes[MN*8], lazy[MN*8];

// Build and init tree

void build_tree(int node, int left, int right) {
   if (left > right) return;
   if (left == right) {
      nodes[node] = a[left];
      return;
   }
   int mid = (left+right)/2;
   build_tree(2*node, left, mid);
   build_tree(2*node+1, mid+1, right);
   nodes[node] = max(nodes[2*node], nodes[2*node+1]);
}

// Increment elements within range [u, v] with value val

void lazy_update(int node) {
   nodes[node] += lazy[node];
   lazy[2*node] += lazy[node];
   lazy[2*node+1] += lazy[node];
   lazy[node] = 0;
}

void update_tree(int node, int left, int right, int u, int v, long long val) {
   lazy_update(node);
   if (u > right || v < left) return;
   if (u <= left && v >= right) {
      nodes[node] += val;
      lazy[2*node] += val;
      lazy[2*node+1] += val;
      return;
   }
   int mid = (left+right)/2;
   update_tree(2*node, left, mid, u, v, val);
   update_tree(2*node+1, mid+1, right, u, v, val);
   nodes[node] = max(nodes[2*node], nodes[2*node+1]);
}

// Query tree to get max element value within range [u, v]

long long query_tree(int node, int left, int right, int u, int v) {
   lazy_update(node);
   if (u > right || v < left) return -1;
   if (u <= left && v >= right) return nodes[node];
   int mid = (left+right)/2;
   return max(query(2*node, left, mid, u, v), query(2*node+1, mid+1, right, u, v));
}
