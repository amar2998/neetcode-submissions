class LRUCache {

    private static class Node{
        int key, val;
        Node prev,next;
        Node(int key,int val){
            this.key=key;
            this.val=val;
        }
    }

    private final int capacity;
    private final Map<Integer,Node> map;
    private final Node head,tail;
    public LRUCache(int capacity) {
        this.capacity=capacity;
        this.map=new HashMap<>();
        this.head=new Node(0,0);
        this.tail=new Node(0,0);
        this.head.next=tail;
        this.tail.prev=head;
    }
    
    public int get(int key) {
        Node node=map.get(key);
        if(node == null){
            return -1;
        }
        moveToFront(node);
        return node.val;
    }
    
    public void put(int key, int value) {
        Node node=map.get(key);
        if(node!=null){
            node.val=value;
            moveToFront(node);
        }
        else{
            Node newNode= new Node(key,value);
            map.put(key,newNode);
            insertAtFront(newNode);
            if(map.size() > capacity){
                Node lru=tail.prev;
                remove(lru);
                map.remove(lru.key);
            }
        }
    }

    private void remove(Node node){
        node.prev.next=node.next;
        node.next.prev=node.prev;

    }

    private  void insertAtFront(Node node){
        node.next=head.next;
        node.prev=head;
        head.next.prev=node;
        head.next=node;
    }

    private void moveToFront(Node node){
        remove(node);
        insertAtFront(node);
    }
}
