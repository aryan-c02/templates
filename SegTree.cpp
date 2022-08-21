class SegTree{

vector<ll> seg;

public:
 
SegTree(int n)
{
   seg.resize(4*n + 1);
}

void build(ll index,  ll low, ll high, vector<ll> &v)
{
   ll mid = low + (high - low)/2;
   if(low >= high)
   {
      seg[index] = v[low];
      return ;
   }
   build( 2*index+1, low, mid, v);
   build( 2*index+2, mid+1, high, v);
   
   seg[index] = (seg[2*index+1] ^ seg[2*index+2]);
   
   
   
}

ll query(ll index, ll low, ll high, ll l, ll r)
{
   if(low > r || high < l) return 0;
   else if(low >= l && high <= r) return seg[index];
   else
   {
      ll mid = low + (high - low)/2;
      ll left = query( 2*index+1, low, mid, l, r);
      ll right = query( 2*index+2, mid+1, high, l, r);
      return (left + right);
   }
   
}

void update( ll index, ll low, ll high, ll a, ll  b, ll value)
{
   
}
};
