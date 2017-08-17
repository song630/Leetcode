#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
// a simpler solution: every time arrow shots points[i].second,
// if points[i+1] <= points[i].second, it is also shot.

class Solution {
public:
    int findMinArrowShots(vector< pair<int, int> >& points) {
        if(points.size() == 0)
        	return 0;
        if(points.size() == 1)
        	return 1;
        int arrows = 0;
        sort(points.begin(), points.end()); // sort by the first x coordinate

        while(points.size() > 1)
        {
            int n = points.size();
            int cursor_index = n - 1;
            pair<int, int> union_segment(points[n-1].first, points[n-1].second);
            int count = 1;
            while(cursor_index > 0 && points[cursor_index-1].second >= union_segment.first)
            {
                union_segment.first = max(union_segment.first, points[cursor_index-1].first);
                union_segment.second = min(union_segment.second, points[cursor_index-1].second);
                cursor_index--;
                count++;
            }
            while(count > 0)
            {
                points.pop_back();
                count--;
            }
            arrows++;
        }
        if(points.size() == 1)
            ++arrows;
        return arrows;
    }
};

int main(void)
{
	pair<int, int> seg0(60051528, 100384399);
	pair<int, int> seg1(12805732, 32854561);
	pair<int, int> seg2(78409503, 93939522);
	pair<int, int> seg3(13258270, 86621638);
	pair<int, int> seg4(9959708, 87446423);
	pair<int, int> seg5(73226340, 104744489);
	pair<int, int> seg6(747796, 90448519);
	pair<int, int> seg7(17142618, 85144863);
	pair<int, int> seg8(50122846, 89616297);
	pair<int, int> seg9(90892921, 151136476);
	vector< pair<int, int> > a;
	a.push_back(seg0);
	a.push_back(seg1);
	a.push_back(seg2);
	a.push_back(seg3);
	a.push_back(seg4);
	a.push_back(seg5);
	a.push_back(seg6);
	a.push_back(seg7);
	a.push_back(seg8);
	a.push_back(seg9);
    /*
    pair<int, int> seg0(-1, 1);
    pair<int, int> seg1(0, 1);
    pair<int, int> seg2(2, 3);
    pair<int, int> seg3(1, 2);
    vector< pair<int, int> > a;
    a.push_back(seg0);
    a.push_back(seg1);
    a.push_back(seg2);
    a.push_back(seg3);
    */
	Solution s;
	cout << s.findMinArrowShots(a) << endl;

	system("pause");
	return 0;
}
