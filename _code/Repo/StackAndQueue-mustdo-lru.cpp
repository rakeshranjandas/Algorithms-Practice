
#include<bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    LRUCache(int );
 
    int get(int );
 
    void set(int , int );
};

struct info {
    int version;
    bool valid;
    int value;
    
    info(int v) {
        version = 0;
        valid = true;
        value = v;
    };
    
    void update(int new_value) {
        value = new_value;
        version++;
        valid = true;
    }

    void update() {
        version++;
        valid = true;   
    }
    
    void invalidate() {
        valid = false;
    }
};

int validCount, maxCount;
queue<pair<int, int> > q;
map<int, info*> m;

void printMap() {
    cout << endl << "---" ;
    for (auto x: m) {
        cout << x.first << "-(" << x.second->value 
            << "," << x.second->valid << "," << x.second->version << ") ";
    }
    cout << endl;
}

void printQueue(queue<pair<int, int>> q) {

    while (!q.empty()) {
        cout << q.front().first << "<" << q.front().second << "> ";
        q.pop();
    }
    cout << endl;
}

LRUCache::LRUCache(int N)
{
    while (!q.empty())
        q.pop();
    
    validCount = 0;
    maxCount = N;
    m.clear();
}
/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y) 
{
    int version;
    bool new_key = true;
        // printMap();
    if (m.find(x) != m.end()) {
        new_key = !m[x]->valid;

        m[x]->update(y);
        version = m[x]->version;
        
    } else {
        m[x] = new info(y);
        version = 0;
    }


    // cout << "--\n";
    // cout << "now " << x << "\n";
    // cout << "prev q state ";
    // printQueue(q);
    // cout << "validCount " << validCount << endl;

    if (new_key) {
        if (validCount >= maxCount) {

            while (!q.empty()) {
                if ((q.front()).second == m[(q.front()).first]->version) {
                    // found
                    // cout << "invalidate " << (q.front()).first << endl;
                    m[(q.front()).first]->invalidate();
                    q.pop();
                    break;
                }
                // cout << "pop " << q.front().first << endl;
                q.pop();
            }

        } else {
            // cout << "only added\n";
            validCount++;
        }
    }
    
    q.push(make_pair(x, version));
    // cout << "new q state ";
    // printQueue(q);
}


/*Returns the value of the key x if 
present else returns -1 */
int LRUCache::get(int x)
{
    // printMap();
    // cout << "fetch prev q state ";
    // printQueue(q);

    int return_val = -1;

    if (m.find(x) != m.end() && m[x]->valid) {
        return_val = m[x]->value;
        m[x]->update();
        q.push(make_pair(x, m[x]->version));
    }

    // cout << "fetch " << x << " ";
    // cout << "fetch new q state ";
    // printQueue(q);

    return return_val;
    // return -1;
}


int main()
{

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        #else
    #endif

    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    LRUCache *l  = new LRUCache(n);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        string a;
        cin>>a;
        if(a=="SET")
        {
            int aa,bb;
            cin>>aa>>bb;
            l->set(aa,bb);
        }else if(a=="GET")
        {
            int aa;
            cin>>aa;
            cout<<l->get(aa)<<" ";
        }
    }
    cout<<endl;
    }
}
