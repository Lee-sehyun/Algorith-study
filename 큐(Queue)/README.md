Queue
========================

큐(Queue)는 먼저 들어온 것이 먼저 나가는 FIFO(First In First Out) 구조를 가진 자료 구조이다.
* 큐(Queue)의 함수
    * 큐에서 데이터를 넣는 것을 Enqueue 
    * 큐에서 데이터를 꺼내는 것을 Dequeue
    * 큐의 제일 앞부분 front
    * 큐의 가장 뒷부분을 rear
    * 큐이 비었는지 확인하는 부분을 isEmpty

큐(Queue)는 배열(Array)기반 큐와 연결리스트(Linked List)기반 큐가 있다.
* 배열(Array)기반 큐
    * 장점
        * 구현이 쉽다.
        * 데이터의 접근 속도가 빠르다.
    * 단점
        * 데이터의 최대 개수를 미리 정해야한다.
        * 데이터의 삽입과 삭제에 있어 매우 비효율 적이다.
* 연결리스트(Linked List)기반 스택
    * 장점
        * 데이터의 최대 개수가 한정되어 있지 않다.
        * 데이터의 삽입과 삭제가 용의하다.
    * 단점
        * 한번에 원하는 데이터의 접근이 불가능하다.


구현 예시) 
* [Array기반 큐 코드](ArrayQueue.cpp)
* [Linked List기반 큐 코드](LinkedlistQueue.cpp)