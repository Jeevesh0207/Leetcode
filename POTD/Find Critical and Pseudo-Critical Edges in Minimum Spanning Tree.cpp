class DSU {

  int n;
  vector < int > parent;
  vector < int > size;

  public:

    DSU(int _n) {
      n = _n + 1;
      parent.resize(n + 1);
      size.resize(n + 1, 0);

      for (int i = 0; i < n; i++)
        parent[i] = i;
    }

  int getParent(int a) {
    if (a == parent[a])
      return a;

    return parent[a] = getParent(parent[a]);
  }

  bool merge(int a, int b) {
    int pa = getParent(a);
    int pb = getParent(b);

    if (pa == pb)
      return false;

    parent[pa] = pb;

    if (size[pa] > size[pb])
      swap(pa, pb);

    size[pb] += size[pa];
    parent[pa] = pb;

    return true;
  }
};

class Solution {
  public:

    int getMst(vector < vector < int >> & eds, int n) {
      DSU kruskal(n);

      int cnt = 0;
      int ans = 0;
      for (int i = 0; i < eds.size(); i++) {

        if (cnt == n - 1)
          break;

        int wt = eds[i][0];
        int a = eds[i][1];
        int b = eds[i][2];

        int pa = kruskal.getParent(a);
        int pb = kruskal.getParent(b);

        if (pa != pb) {
          cnt++;
          kruskal.merge(pa, pb);
          ans += wt;
        }
      }
      if (cnt < n - 1)
        return 1e9;

      return ans;
    }

  int fixMst(vector < vector < int >> & eds, int i, int n) {
    DSU kruskal(n);
    int cnt = 1;
    int ans = eds[i][0];

    kruskal.merge(eds[i][1], eds[i][2]);

    for (int i = 0; i < eds.size(); i++) {

      if (cnt == n - 1)
        break;

      int wt = eds[i][0];
      int a = eds[i][1];
      int b = eds[i][2];

      int pa = kruskal.getParent(a);
      int pb = kruskal.getParent(b);

      if (pa != pb) {
        cnt++;
        kruskal.merge(pa, pb);
        ans += wt;
      }
    }
    if (cnt < n - 1)
      return 1e9;

    return ans;
  }

  int remMst(vector < vector < int >> & eds, int j, int n) {
    DSU kruskal(n);
    int cnt = 0;
    int ans = 0;

    int n1 = eds[j][1];
    int n2 = eds[j][2];

    for (int i = 0; i < eds.size(); i++) {
      if (i == j)
        continue;

      if (cnt == n - 1)
        break;

      int wt = eds[i][0];
      int a = eds[i][1];
      int b = eds[i][2];

      int pa = kruskal.getParent(a);
      int pb = kruskal.getParent(b);

      if (pa != pb) {
        cnt++;
        kruskal.merge(pa, pb);
        ans += wt;
      }
    }
    if (cnt < n - 1)
      return 1e9;

    return ans;
  }

  vector < vector < int >> findCriticalAndPseudoCriticalEdges(int n, vector < vector < int >> & edges) {

    vector < vector < int >> ans;

    vector < int > critical, noncritical;
    set < int > st;
    int sz = edges.size();

    vector < vector < int > > eds;

    for (int i = 0; i < edges.size(); i++) {
      eds.push_back({
        edges[i][2],
        edges[i][0],
        edges[i][1],
        i
      });
    }

    sort(eds.begin(), eds.end());

    int mst = getMst(eds, n);

    for (int i = 0; i < sz; i++) {
      int rmst = remMst(eds, i, n);

      if (rmst > mst) {

        critical.push_back(eds[i][3]);
        st.insert(eds[i][3]);
      }
    }

    ans.push_back(critical);
    for (int i = 0; i < eds.size(); i++) {
      int rmst = fixMst(eds, i, n);

      if (rmst == mst && st.find(eds[i][3]) == st.end()) {
        noncritical.push_back(eds[i][3]);
      }
    }

    ans.push_back(noncritical);
    return ans;
  }
};
