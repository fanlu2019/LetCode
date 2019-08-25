给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    struct ListNode* head = NULL;
    struct ListNode* curNode = NULL;
    struct ListNode* tempNode = NULL;
    int addBit = 0;
    int temp = 0;   
    int tempBit = 0;   
    
    while (l1 != NULL || l2 != NULL) {
        tempNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (tempNode == NULL) {
            return NULL;        
        }
        
        temp = 0;
        
        if (l1 != NULL) {
            temp = temp + l1->val;    
            //printf("l1->val=%u ", l1->val);
        }
        
        if (l2 != NULL) {
            temp = temp + l2->val;   
            //printf("l2->val=%u ", l2->val);
        }
        
        tempBit = addBit;
        addBit = 0;
        
        if (temp + tempBit >= 10) {
            temp = temp + tempBit - 10;            
            addBit = 1;    
        } else {
            temp = temp + tempBit; 
        }  
        //printf("temp=%u, addBit=%u \r\n", temp, addBit);        
        
        tempNode->val = temp;
        tempNode->next = NULL;
        
        if (head == NULL) {
            head = tempNode;
            curNode = head;
        } else {
            curNode->next = tempNode;
            curNode = tempNode;            
        }
        
        if (l1 != NULL) {
            l1 = l1->next;            
        }
        
        if (l2 != NULL) {
            l2 = l2->next;            
        }
    }
    
    if (addBit == 1) {
        tempNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (tempNode == NULL) {
            return NULL;        
        }
        
        tempNode->val = 1;
        tempNode->next = NULL;
        
        if (head == NULL) {
            head = tempNode;
            curNode = head;
        } else {
            curNode->next = tempNode;
            curNode = tempNode;            
        }        
    }    
    
    return head;
}