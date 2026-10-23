class Node{
public:
    int data,key;
    Node* prev;
    Node* next;

    Node(int ky,int val){
        key=ky;
        data=val;
        prev=nullptr;
        next=nullptr;
    }
};
class LRUCache {
public:
    int cap;
    unordered_map<int,Node*>mp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        Node* nd=mp[key];
        delnd(nd);
        insnd(nd);
        return nd->data;
    }
    
    void put(int key, int value) {
        if(cap==0)return;
        if(mp.find(key)!=mp.end()){
            Node* nd=mp[key];
            nd->data=value;
            delnd(nd);
            insnd(nd);
        }
        else{
            if(mp.size()==cap){
                Node* nd=tail->prev;
                delnd(nd);
                mp.erase(nd->key);
            }
            Node* nd=new Node(key,value);
            mp[key]=nd;
            insnd(nd);
        }

    }
    void delnd(Node* nd){
        Node* ndP=nd->prev;
        Node* ndN=nd->next;
        ndP->next=ndN;
        ndN->prev=ndP;
       
    }
    void insnd(Node* nd){
        Node* nextohd=head->next;
        head->next=nd;
        nd->prev=head;
        nd->next=nextohd;
        nextohd->prev=nd;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */