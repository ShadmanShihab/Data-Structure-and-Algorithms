/*Custom Compare
Using this function in sort with sort vector of pairs in such a way first is smaller and if both are same then second is smaller.
 Thus changing the sign we can fill our need.
 */

bool cmp(const pair<int,int> &a,const pair<int,int> &b) {
	if (a.first != b.first) return a.first < b.first;
	return a.second < b.second;
}
