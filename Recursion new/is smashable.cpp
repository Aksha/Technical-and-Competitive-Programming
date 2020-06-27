//dict = {interview, kickstart, is , awesome}
//word = sprint
// output = true 


/*
              sprint
           / / /\ \ \ 
   (print)(spint) srint sprnt sprin
   ///\\   //\               
  rint pint prit prin pint sint spint spin               


    vector<string> isSmashable(string S, unordered_set<string> dictionary, vector<string> path) {
        if(S.size() == 1) //base case {     
            return path;
        }
        for(int i = 0; i < S.size();i++) {
            if(dictionary.find(S.substr(0,i) + S.substr(i+1)) != dictionary.end(){
                path.push_back(S.substr(0,i) + S.substr(i+1));
                isSmashable(S.substr(0,i) + S.substr(i+1), dictionary, path); 
            }
        }
        return path;
    }                 
                 
                  
                  sprint -> print -> pint -> int -> it -> t  
                  
                  sprint
                  
     (print)
    
   (rint) (pint)
       
                  
          (int)
                  
          (nt) (it)
                  
                (t)  
*/


  vector<string> isSmashable(string S, unordered_set<string> dictionary, vector<string> path) {
        if(S.size() == 1) //base case {     
            return path;
        }
        for(int i = 0; i < S.size();i++) {
            if(dictionary.find(S.substr(0,i) + S.substr(i+1)) != dictionary.end(){
                path.push_back(S.substr(0,i) + S.substr(i+1));
                isSmashable(S.substr(0,i) + S.substr(i+1), dictionary, path); 
            }
        }
        return path;
    }

