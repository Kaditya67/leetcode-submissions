class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        char e;
        for(char &num:str){
            if(num!='9'){
                e = num;
                break;
            }
        }

        string maxNum = "";
        for(char &num:str){
            if(num == e) maxNum+='9';
            else maxNum+= num;
        } 

        string minNum="";
        for(char &num:str){
            if(num==str[0]) minNum+='0';
            else minNum+=num;
        }
        return stoi(maxNum)-stoi(minNum);
    }
};