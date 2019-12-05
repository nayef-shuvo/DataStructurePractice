import matplotlib.pyplot as plt
#import time
import timeit

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList(Node):
    def __init__(self):
        self.head = None
        self.size = 0
    
    def insert(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            last_node = self.head
            while last_node.next != None:
                last_node = last_node.next
            last_node.next = new_node
        self.size += 1

    def show(self):
        cur_node = self.head
        if cur_node is None:
            print('Linked list is empty!')
            return None
        while True:
            print(cur_node.data, end = ' ')
            cur_node = cur_node.next
            if cur_node is None:
                break
        print()

    def iloc(self, index): #* return value of an index 
        cur_node = self.head
        for i in range(self.size):
            if i == index:
                return cur_node.data
            cur_node = cur_node.next

    def length(self):
        return self.size


if __name__ == "__main__":
    array_list = []
    linked_list = LinkedList()

    rng = int(input('Enter a range.. '))

    tmp = timeit.default_timer()
    for i in range(1, rng+1):
        array_list.append(i)
    time1 = (timeit.default_timer()-tmp)*1000
    
    tmp = timeit.default_timer()
    for i in range(1, rng+1):
        linked_list.insert(i)
    time2 = (timeit.default_timer()-tmp)*1000

    plot_list = [time1, time2]
    xpos = [0, .9]
    plt.title('Time Consumption in Inserting Element')
    plt.xticks(xpos, ['Array', 'Linked List'])
    plt.ylabel('Time (in nano second)')
    plt.bar(0, time1, width=.5)
    plt.bar(1, time2, width=.5)

    plt.legend(['Array', 'Linked List'])
    plt.show()
