/**
 * 381. O(1) 时间插入、删除和获取随机元素 - 允许重复
设计一个支持在平均 时间复杂度 O(1) 下， 执行以下操作的数据结构。

注意: 允许出现重复元素。

insert(val)：向集合中插入元素 val。
remove(val)：当 val 存在时，从集合中移除一个 val。
getRandom：从现有集合中随机获取一个元素。每个元素被返回的概率应该与其在集合中的数量呈线性相关。
示例:

// 初始化一个空的集合。
RandomizedCollection collection = new RandomizedCollection();

// 向集合中插入 1 。返回 true 表示集合不包含 1 。
collection.insert(1);

// 向集合中插入另一个 1 。返回 false 表示集合包含 1 。集合现在包含 [1,1] 。
collection.insert(1);

// 向集合中插入 2 ，返回 true 。集合现在包含 [1,1,2] 。
collection.insert(2);

// getRandom 应当有 2/3 的概率返回 1 ，1/3 的概率返回 2 。
collection.getRandom();

// 从集合中删除 1 ，返回 true 。集合现在包含 [1,2] 。
collection.remove(1);

// getRandom 应有相同概率返回 1 和 2 。
collection.getRandom();
 */


import java.util.*;


class RandomizedCollection {

    private List<Integer> arr = new ArrayList<>();

    private int tail = -1;

    private Map<Integer, LinkedList<Integer>> map = new HashMap<>();

    private final Random random = new Random();

    /**
     * Initialize your data structure here.
     */
    public RandomizedCollection() {}

    /**
     * Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
     */
    public boolean insert(int val) {
        arr.add(++tail, val);
        LinkedList<Integer> indexes = map.computeIfAbsent(val, (k) -> new LinkedList<>());
        indexes.addFirst(tail);
        return indexes.size() == 1;
    }

    /**
     * Removes a value from the collection. Returns true if the collection contained the specified element.
     */
    public boolean remove(int val) {
        LinkedList<Integer> indexes = map.get(val);
        if(indexes == null || indexes.size() == 0){
            return false;
        }

        int idx = indexes.removeFirst();
        if(idx < tail){

            int lastVal = arr.get(tail);
            arr.set(idx, lastVal);

            LinkedList<Integer> lastValIndexes = map.get(lastVal);

            Iterator<Integer> iter = lastValIndexes.iterator();
            int cnt = 0;
            while (iter.hasNext()){
                Integer next = iter.next();
                if(next < idx){
                    break;
                }
                cnt++;
            }
            lastValIndexes.add(cnt, idx);

            lastValIndexes.removeFirst();


        }

        --tail;

        return true;

    }

    /**
     * Get a random element from the collection.
     */
    public int getRandom() {
        int i = random.nextInt(tail + 1);
        return arr.get(i);
    }

    public static void main(String[] args) {
        System.out.println(1);
    }
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
