%
% Bryan Kline
% CS326 HW #7
% Prolog
%


%1.

% if the list is empty return the empty list
reverse([], []).
% the recursive call to reverse, appending what ever it comes back with 
% to H and putting it in L1
reverse([H|T], L1) :-  reverse(T, L2), append(L2, [H], L1).


%2.

% function to return the number of elements in a list
% if the list is empty return zero
numElements([], 0).
% the recursive call on the tail, setting X to what ever it comes back 
% with plus one
numElements([_|T], X) :- numElements(T, X1), X is X1 + 1.

% if N is zero then return the empty list
take(_, 0, []).
% if N is greater than the number of elements in the list, return the entire list
take(L1, N, L1) :- numElements(L1, X), X =< N.
% recursive call on the tail, returning L2 which is appended to the head and put 
% in L1, N is decremented
take([H|T], N, L1) :- X is N - 1, take(T, X, L2), append([H], L2, L1).


%3.

% tree definition
tree(nil).
tree(node(_, Left, Right)) :- tree(Left), tree(Right).

%a

% if at a leaf, return 1
nleaves(node(_, nil, nil), N) :- N is 1.
% recursive call on the left and right subtrees, setting N to the sum of their calls
nleaves(node(_, Left, Right), N) :- nleaves(Left, N2), nleaves(Right, N3), N is N2 + N3.

%b

% if E is found, return true
treeMember(E, node(E, _, _)).
% if there is a left, recurse left
treeMember(E, node(_, Left, _)) :- treeMember(E, Left).
% if there is a right, recurse right
treeMember(E, node(_, _, Right)) :- treeMember(E, Right).

%c
% if at a leaf, return that nodes value in a list
preOrder(node(N, nil, nil), [N]).
% if there is a left child but no right, recurse left and append what it comes back 
% with to L, the tail
preOrder(node(H, Left, nil), [H|L]) :- preOrder(Left, L1), append(L1, [], L).
% if there is a right child but no left, recurse right and append what it comes back
% with to L, the tail
preOrder(node(H, nil, Right), [H|L]) :- preOrder(Right, L1), append([], L1, L).
% if there are both right and left children, recurse left and right and append what they come back
% with to L, the tail
preOrder(node(H, Left, Right), [H|L]) :- preOrder(Left, L1), preOrder(Right, L2), append(L1, L2, L).

%d
% if at a leaf, set N to 1
height(node(_, nil, nil), N) :- N is 1.
% if there is a left child but no right, recurse left and add what it comes back with to 1 and set N 
% to that
height(node(_, Left, nil), N) :- height(Left, N1), N is N1 + 1.
% if there is a right child but no left, recurse right and add what it comes back with to 1 and set N 
% to that
height(node(_, nil, Right), N) :- height(Right, N1), N is N1 + 1.
% if there are both right and left children, curse left and right, get the max of their returns, add 1 
% to that and set N to that
height(node(_, Left, Right), N) :- height(Left, N1), height(Right, N2), N3 is max(N1, N2), N is N3 + 1.


%4.
% if at the end of the list, return the list containing N
insert(N, [], [N]). 
% if N is less than the head, append N to the list and return it
insert(N, [H|T], L) :- N < H,  append([N], [H|T] , L).
% if N is greater than or equal to the head, the recurse on the tail and append what
% it comes back with to the head and put that in L
insert(N, [H|T], L) :- N >= H, insert(N, T, L1), append([H], L1, L).


%5. Extra Credit
% if just the head remains, return the list containing the head
flatten([H|[]], [H]).
% if the head is a list, recurse on the head of the head, its tail, and the tail, and append them
flatten([[H|T1]|T2], L) :- flatten([H], L4), flatten(T1, L1), flatten(T2, L2), append(L1, L2, L3), append(L4, L3, L).
% if the head is not a list, call flatten on the head and the tail and append them
flatten([H|T], L) :- flatten([H], L1), flatten(T, L2), append(L1, L2, L).
