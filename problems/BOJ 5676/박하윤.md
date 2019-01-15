- 내가 이해한 문제내용
	- N개의 정수로 이루어진 수열을 입력받고 친구가 K번 동안 명령어를 입력한다. C혹은 P. C일 경우 변경 명령으로 i번째 수열을 주어진 다른 숫자로 바꾸고 P일 경우 i번 부터 j번까지 수열의 곱을 구하여 양수인지, 음수인지, 0인지를 구하여 출력한다.


- 접근방식
	- 반복문과 그 안에 if문을 활용하여 하나씩 계산하여 보았었는데 값이 제대로 나오지도 않고 중간에 입력이 끊기는 경우가 계속 발생하여 세그먼트 트리로 알아봄
	- 세그먼트 트리: 부모 노드가 자신의 자식노드끼리의 합 혹은 곱(빼기도 되고 나누기도 가능)을 가지고 있는 트리 형태 - 보통은 완전 이진 트리의 형태


- 어려웠던 점
	- 여러 풀이를 보면서 이해한 내용을 바탕으로 구현했는데 계속 런타임 에러.. 시간 초과.. => 그 코드는 가지고 있으면서 스스로 고쳐보고자 함
	- 결국 한 풀이를 그대로 적어가면서 이해 => 살펴보니 변수들이 꼬여서 순서가 뒤죽박죽으로 주어지는 경우를 발견함 => 그 부분만 고쳐봤는데도 계속 런타임 에러..
	- 세그먼트 구현할 때 사용되는 식을 이해하는데 시간이 걸림 

- 복잡도
	- 시간복잡도: O(KlogN) => 세그먼트 트리 + 값을 갱신하는 값
	- 공간복잡도: O(N) => 일차원 배열

- 참고한 사이트
	- http://onlyhim.tistory.com/15 (코드)
	- https://blog.naver.com/PostView.nhn?blogId=proability&logNo=221299561447&categoryNo=8&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=&from=postList&userTopListOpen=true&userTopListCount=5&userTopListManageOpen=false&userTopListCurrentPage=1 (코드)
	- https://wkdtjsgur100.github.io/segment-tree/ (개념이해)
	- https://kks227.blog.me/220791986409?Redirect=Log&from=postView (개념이해)
