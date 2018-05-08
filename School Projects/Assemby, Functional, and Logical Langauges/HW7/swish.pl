flatten([H|[]], [H]).
flatten([[H|T1]|T2], L) :- flatten([H], L4), flatten(T1, L1), flatten(T2, L2), append(L1, L2, L3), append(L4, L3, L).
flatten([H|T], L) :- flatten([H], L1), flatten(T, L2), append(L1, L2, L).

%flatten([[]|T], T).
%flatten([[H|[]]|[]], H).
