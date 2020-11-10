int search_1(int l, int r)
{
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	return l;
 } 
 
 int seatch_2(int l, int r)
 {
 	while(l < r)
 	{
 		int mid = l + r + 1>> 1;
 		if( check(mid)) l = mid;
 		else r = mid - 1;
	 }
 }
