class Main {

	public static void main(String[] args) {
		LRUCache obj = new LRUCache(2);
		obj.put(1, 1);
		obj.put(2, 2);
		System.out.println(obj.get(1)); // 1
		obj.put(3, 3);
		System.out.println(obj.get(2)); // -1
		obj.put(4, 4);
		System.out.println(obj.get(1)); // -1
		System.out.println(obj.get(3)); // 3
		System.out.println(obj.get(4)); // 4
	}
}
