import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class _5601 {
    class OrderedStream {
        private String[] arr;
        private int n;
        private int ptr;

        public OrderedStream(int n) {
            this.n = n;
            this.ptr = 1;
            this.arr = new String[n + 1];
        }

        public List<String> insert(int id, String value) {
            arr[id] = value;

            List<String> res = new ArrayList<>();
            while (ptr <= n && arr[ptr] != null) {
                res.add(arr[ptr]);
                ptr++;
            }
            return res;
        }
    }

    /**
     * Your OrderedStream object will be instantiated and called as such:
     * OrderedStream obj = new OrderedStream(n); List<String> param_1 =
     * obj.insert(id,value);
     */
}