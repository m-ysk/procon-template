const int UF_MAX_N = 101010;

int uf_parant[UF_MAX_N];
int uf_rank[UF_MAX_N];
int uf_group_size[UF_MAX_N];

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        uf_parant[i] = i;
        uf_rank[i] = 0;
        uf_group_size[i] = 1;
    }
}

int find(int x)
{
    if (uf_parant[x] == x)
    {
        return x;
    }
    else
    {
        return uf_parant[x] = find(uf_parant[x]);
    }
}

int get_size(int x)
{
    x = find(x);
    return uf_group_size[x];
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;

    if (uf_rank[x] < uf_rank[y])
    {
        uf_parant[x] = y;
        uf_group_size[y] += uf_group_size[x];
    }
    else
    {
        uf_parant[y] = x;
        uf_group_size[x] += uf_group_size[y];
        if (uf_rank[x] == uf_rank[y])
            uf_rank[x]++;
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}
