# TIL 26/02/15 - Java length와 length()

자바에 조금씩 익숙해지는 중. 

배열, 문자열의 길이 재는 기능을 사용하니 헷갈리는 부분이 생겼다.

- Array의 길이를 구할 땐 `arr.length`
- String의 길이를 구할 땐 `str.length()`

둘 사이에 무슨 차이가 있길래 어떨 땐 `()`가 붙고 어떨 땐 안 붙을까?

검색해보니 나랑 똑같은 의문을 가진 스택오버플로우 질문 글이 있었다. 답변을 읽어보니 의문을 없앨 수 있었다.

---

### length, length(), size()

세 가지 방법 모두 유사한 기능을 수행한다.

1. `length`는 Array의 길이를 알려준다.
2. `length()`는 String 객체의 길이를 알려준다.
3. `size()`는 Collection 객체(ArrayList, Set ...)의 길이를 알려준다.

`length`는 **메서드가 아니다** 배열은 크기가 정해지면 변하지 않는다.
배열의 길이는 미리 저장되어 있고 `array.length`는 length라는 필드를 읽어오는것 뿐이다.

length는 자바의 **built-in property**다.

`length()`는 메서드다. String 클래스 내부에 정의된 length()메서드를 사용해 길이를 알 수 있다.

`java.lang` 내부에 있는 String 클래스의 `length()` 메소드를 찾아보면 아래와 같다.

```java
public int length() {  
    return value.length >> coder();  
}
```

String 객체의 length 필드를 반환하고 있다!

나처럼 다들 해당 내용이 헷갈리는지 W3Schools의 [array length property](https://www.w3schools.com/java/ref_arrays_length.asp) 문서에도 아래와 같이 써 있다.

> [!NOTE]
> **Note:** The `length` **property** must not be mistaken with the [`length()`](https://www.w3schools.com/java/ref_string_length.asp) **method** that is used for Strings.

`size()`도 length() 와 유사하게 길이를 반환하는 메서드이다.

문자열 String이 아닌 콜렉션 객체에서 사용할 수 있는 메서드임!

### 정리

- 배열의 길이를 알려주는 `arr.length`는 이미 정해진 필드를 읽어오는 것이기 때문에 `()`가 붙지 않는다.

- 문자열의 길이를 알려주는 `str.length()`는 주어진 문자열의 길이를 반환하는 메서드를 실행하는 것이기 때문에 `()`가 붙는다.

---

### 참고한 글

- [length and length() in Java, Stack Overflow](https://stackoverflow.com/questions/1965500/length-and-length-in-java)
- [Java Array length Property, W3Schools](https://www.w3schools.com/java/ref_arrays_length.asp)