class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0]==o2[0]) return o1[1]-o2[1];
                return o1[0]-o2[0];
            }
        });
        
        int length = intervals.length;
        List<int[]> res = new ArrayList<int[]>();
        
        int left;
        int right;
        //boolean restart = true;
        
        if (length <= 1) return intervals;
        
        //初始化
        left = intervals[0][0];
        right = intervals[0][1];
        
        for (int i = 1; i < length; i++) {
            if (intervals[i][0] > right) {  //与上一区间不重合
                int[] temp = new int[2];
                temp[0] = left;
                temp[1] = right;
                res.add(temp);
                
                left = intervals[i][0];
                right = intervals[i][1];
                
            } else {    //与上一区间重合
                left = left < intervals[i][0] ? left : intervals[i][0];
                right = right > intervals[i][1] ? right : intervals[i][1];
            }
            
            if (i == length - 1) {  //当前为最后一个区间
                int[] temp = new int[2];
                temp[0] = left;
                temp[1] = right;
                res.add(temp);
            }
        }
        
        return res.toArray(new int[res.size()][2]); //记住 list.size() 用法
    }
}