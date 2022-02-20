class Solution{
public:
   int scheduleCourse(vector<vector<int>>& courses) {
	int n=courses.size();
	std::priority_queue<int> pq;
	std::sort(courses.begin(),courses.end(),[] (auto &a,auto &b){
		return a[1]<b[1];
	});
	int time=0;
	for(auto &it:courses){
        int x=it[0];
        int y=it[1];
		if(x<=y){
		  if(time+x<=y){
		  	pq.push(x);
		  	time+=x;
		}			
		else{
			if(pq.top()>x){
				time-=pq.top();
                pq.pop();
				time+=x;
				pq.push(x);
			}
		}
	}
}
	return pq.size();
}
};