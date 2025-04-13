/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int start=0; int end= 1;
        while(reader.get(end)<target){
            start=end; end= end*2;

        }
        while(start<=end){
            int mid= (end-start)/2+start;
            if(reader.get(mid)<target)start= mid+1;
             if(reader.get(mid)>target)end= mid-1;
             if(reader.get(mid)==target)return mid;


        }
        return -1;
    }
};