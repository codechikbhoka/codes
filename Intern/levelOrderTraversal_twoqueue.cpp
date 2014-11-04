void printTree(node* root){
    vector<node*> q[2];
    cur = 0;
    q[cur].push_back(root);
    while (!q[cur].empty()){
        int nxt = (cur+1)%2;
        for (vector<node*>::iterator x = q[cur].begin(); x!=q[cur].end(); x++){
            cout<<(*x)->data<<" ";
            if ((*x)->left) q[nxt].push_back((*x)->left);
            if ((*x)->right) q[nxt].push_back((*x)->right);
        }
        cout<<endl;
        q[cur].clear();
        cur=nxt;
    }
}