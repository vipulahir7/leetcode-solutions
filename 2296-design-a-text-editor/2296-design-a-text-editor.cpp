#include<bits/stdc++.h>
class TextEditor {
public:
    
    string textArea;
    int cursor;
    
    TextEditor() {
        textArea="";
        cursor=0;
    }
    
    void addText(string text) {
        int len=text.length();
        textArea.insert(cursor,text);
        cursor+=len;
    }
    
    int deleteText(int k) {
        int lengthTodel;
        if(cursor>=k){
            lengthTodel=k;
        }
        else{
            lengthTodel=cursor;
        }
        textArea.erase(cursor-lengthTodel,lengthTodel);
        cursor-=lengthTodel;
        return lengthTodel;
    }
    
    string cursorLeft(int k) {
        if(cursor-k>=0){
            cursor-=k;
        }
        else{
            cursor=0;
        }
        
        int len=min(10,cursor);
        string temp=textArea.substr(cursor-len,len);
        return temp;
    }
    
    string cursorRight(int k) {
        
        if(cursor+k<=textArea.size()){
            cursor+=k;
        }
        else{
            cursor=textArea.size();
        }
        int len=min(10,cursor);
        return textArea.substr(cursor-len,len);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */