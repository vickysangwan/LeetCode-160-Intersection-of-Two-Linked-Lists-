/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode *head)
    {
        int count=0;
        while(head!=NULL)
        {
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if(headA==NULL || headB==NULL)
        {
            return NULL;
        }
        else
        {
            int d1=length(headA);
            int d2=length(headB);
            if(d1>d2)
            {
                ListNode* temp=headA;
                for(int i=0;i<d1-d2;i++)
                {
                    temp=temp->next;
                }
                while(temp!=NULL && headB!=NULL)
                {
                    if(temp==headB)
                    {
                        return temp;
                    }
                    else
                    {
                        temp=temp->next;
                        headB=headB->next;
                    }
                }
            }
            else if(d1==d2)
            {
                 while(headA!=NULL && headB!=NULL)
                 {
                     if(headA==headB)
                     {
                         return headA;
                     }
                     else
                     {
                         headA=headA->next;
                         headB=headB->next;
                     }
                 }
            }
            else{
                    ListNode* temp=headB;
                    for(int i=0;i<d2-d1;i++)
                    {
                        temp=temp->next;
                    }
                    while(headA!=NULL && temp!=NULL)
                    {
                        if(headA==temp)
                        {
                            return headA;
                        }
                        else
                        {
                            headA=headA->next;
                            temp=temp->next;
                        }
                    }
                }
        }
        return NULL;
    }
};
