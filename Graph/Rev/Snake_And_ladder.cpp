int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
  std::unordered_map<int,int> stairs;  
  std::unordered_map<int,int> snake;
  std:queue<int> qu;
  std::vector<int> visited(101,false);
  qu.push(1); //need to start with 1
  for(auto &it:A){
      stairs[it[0]]=it[1];
  }
  for(auto &it:B){
      snake[it[0]]=it[1];
  }
  int lvl=0;
  while(not qu.empty()){
      int n=qu.size();
      while(n--){
          int curr=qu.front();
          qu.pop();
          visited[curr]=true;
          if(curr==100){
              return lvl;
          }
          for(int i=1;i<=6;i++){
              int pos=curr+i;
              if(pos<=100 && snake.count(pos) && visited[pos]==false){
                  visited[pos]=true;
                  pos=snake[pos];
              }
              if(pos<=100 && stairs.count(pos) && visited[pos]==false){
                  visited[pos]=true;
                  pos=stairs[pos];
              }
              if(visited[pos]==false){
                  qu.push(pos);
                  visited[pos]=true;
              }
          }
      }
      lvl++;
  }
  return -1;
}
