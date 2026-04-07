class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int wn=word.length(), an=abbr.length();
        int i=0,j=0;
        string ch="";
        while(j<an && i<wn){
            if('a'<=abbr[j]&&abbr[j]<='z'){
                if(ch!=""){
                    cout<<abbr[j]<<" "<<ch<<endl;
                    int idx=stoi(ch);
                    if(i+idx<wn && word[i+idx]==abbr[j]) {
                        ch="";
                        i+=idx+1;
                    }
                    else return false;
                } else if(abbr[j]!=word[i]) return false;
                else i+=1;
                j+=1;
            } else {
                if(ch=="" && abbr[j]=='0') return false;
                ch+=abbr[j];
                j+=1;
            }
        }
        if(ch!=""){
            cout<<"entered";
            int idx=stoi(ch);
            if(i+idx==wn) return true;
            return false;
        }
        return true;
    }
};