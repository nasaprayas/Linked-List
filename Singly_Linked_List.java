public class singly_linked_list {
        static class Node {
            int data;
            Node next;
    
            Node(int data) {
                this.data = data;
                this.next = null;
            }
        }
    
        static Node createNode(int data) {
            return new Node(data);
        }
    
        static void insertAtBeginning(Node[] head, int data) {
            Node newNode = createNode(data);
            newNode.next = head[0];
            head[0] = newNode;
        }
    
        static void insertAtEnd(Node[] head, int data) {
            Node newNode = createNode(data);
            if (head[0] == null) {
                head[0] = newNode;
                return;
            }
            Node temp = head[0];
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }
    
        static void insertAtBetween(Node head, int key, int data) {
            Node newNode = createNode(data);
            Node temp = head;
            while (temp != null && temp.data != key) {
                temp = temp.next;
            }
            if (temp == null) {
                System.out.println("Node with key " + key + " not found.");
                return;
            }
            newNode.next = temp.next;
            temp.next = newNode;
        }
    
        static int deleteNode(Node[] head, int key) {
            Node temp = head[0];
            Node prev = null;
            if (temp != null && temp.data == key) {
                head[0] = temp.next;
                return 0;
            }
            while (temp != null && temp.data != key) {
                prev = temp;
                temp = temp.next;
            }
            if (temp == null) {
                return -1; // Node with given key not found
            }
            prev.next = temp.next;
            return 0;
        }
    
        static void printList(Node head) {
            Node temp = head;
            while (temp != null) {
                System.out.print(temp.data + " ");
                temp = temp.next;
            }
            System.out.println();
        }
    }
    
        public static void main(String[] args) {
            Node[] head = new Node[1];
            head[0] = null;
    
            insertAtBeginning(head, 10);
            insertAtBeginning(head, 20);
    
            insertAtEnd(head, 30);
            insertAtEnd(head, 40);
    
            System.out.print("Original List: ");
            printList(head[0]);
    
            insertAtBetween(head[0], 20, 25);
            System.out.print("List after inserting 25 after 20: ");
            printList(head[0]);
        }
    }
    
    

