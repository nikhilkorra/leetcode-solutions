class Solution {
public:
    bool isValidSerialization(string preorder){
        stack<string> s;
        vector<string> tokens;
        stringstream ss(preorder);
        string tmp;
        while(getline(ss, tmp, ',')){
            tokens.push_back(tmp);
        }
        int node_count=1;
        for(auto &token: tokens){
            node_count--;
            if(node_count<0) return false;
            if(token!="#") node_count+=2;
        }
        return node_count==0;
    }
    bool isValidSerializationStack(string preorder) {
        stack<string> s;
        vector<string> tokens;
        stringstream ss(preorder);
        string tmp;
        while(getline(ss, tmp, ',')){
            tokens.push_back(tmp);
        }
        for(auto &token: tokens){
            s.push(token);
            while(s.size()>=3){
                if(s.top()=="#"){
                    s.pop();
                    if(s.top()=="#"){
                        s.pop();
                        if(s.top()!="#"){
                            s.pop();
                            s.push("#");
                        }
                        else return false;
                    }
                    else{
                        s.push("#");
                        break;
                    }
                }
                else break;
            }
        }
        return (s.size()==1 && s.top()=="#");
    }
};