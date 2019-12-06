#include <climits>
#include "Heap.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new heapH[cap];
	
}

// Inserts a new key 'k' 
void MinHeap::insertKey(int k, char* c)
{
	if (heap_size == capacity)
	{
		//cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	// First insert the new key at the end 
	heap_size++;
	int i = heap_size - 1;
	harr[i].priority = k;
	memcpy_s(harr[i].message, sizeof(harr->message), c, strlen(c) + 1);

	// Fix the min heap property if it is violated 
	while (i != 0 && harr[parent(i)].priority > harr[i].priority)
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

// Decreases value of key at index 'i' to new_val.  It is assumed that 
// new_val is smaller than harr[i]. 
void MinHeap::decreaseKey(int i, int new_val)
{
	harr[i].priority = new_val;
	while (i != 0 && harr[parent(i)].priority > harr[i].priority)
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

// Method to remove minimum element (or root) from min heap 
heapH MinHeap::extractMin()
{
	if (heap_size <= 0) {
		harr[0].priority = 10;
		return harr[0];
	}
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	// Store the minimum value, and remove it from heap 
	int root = harr[0].priority;
	heapH temp = harr[0];

	harr[0] = harr[heap_size - 1];
	heap_size--;
	MinHeapify(0);

	return temp;
}


// This function deletes key at index i. It first reduced value to minus 
// infinite, then calls extractMin() 
void MinHeap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	extractMin();
}

// A recursive method to heapify a subtree with the root at given index 
// This method assumes that the subtrees are already heapified 
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l].priority < harr[i].priority)
		smallest = l;
	if (r < heap_size && harr[r].priority < harr[smallest].priority)
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}


void swap(heapH *x, heapH *y)
{
	heapH temp = *x;
	*x = *y;
	*y = temp;
}


/*
 * Need to extract the priority one at a time to get a list of the values, but this then removes it from the heap
 * so we need to extract the messages, then store them in a seperate array, then add them back inot the heap
 */


void MinHeap::Print(void) {
	int size = heap_size;
	copyharr = (heapH*)calloc(size, sizeof(heapH));

	int counter = 0;
	for (int i = 0; i < size; i++) {

		// stores returned values into a array of the heap structs.
		copyharr[i] = heaper.extractMin();
	}
	// When finished loop, the whole heap should be empty
	for (int i = 0; i < size; i++) {

		printf("Priority %d: Message: %s\n", copyharr[i].priority, copyharr[i].message);

		if (copyharr->priority == 10) {
			break;
		}
	}
	
	for (int i = 0; i < size; i++) {

		// stores returned values into a array of the heap structs.
		heaper.insertKey(copyharr[i].priority, copyharr[i].message);
	}
	
}