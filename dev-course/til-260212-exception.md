# TIL 26/02/12 - Java Exception

## 예외 발생

- 프로그램 동작 중 잘못된 값이 입력되거나, 파일이 존재하지 않는 경우 발생
- 에러 발생시 JVM이 프로그램을 강제 종료시킨다.

### 예외 처리

예외가 발생하더라도 프로그램이 강제 종료되지 않도록 하는 방법

**오류 클래스**

오류 클래스는 모두 `Throwable` 클래스를 상속받음

Error 클래스, `Exception` 클래스

Exception 클래스 하위에 입출력 예외 처리(IOException), 런타임 예외 처리(RuntimeException) 존재.

---

### try ~ catch ~finally

1. 에러 발생 가능성이 있는 코드를 **`try`** 에 작성
2. try 작성된 코드에서 예외 발생 시 처리방법을 **`catch`** 에 작성
3. 예외 발생과 상관없이 무조건 실행될 코드는 **`finally`** 블록에 작성

```java
public class ExceptionHandling {  
    public static void main(String[] args) {  
        int[] arr = new int[5];  
        try {  
            for (int i = 0; i <= 5; i++) {  
                arr[i] = i;  
                System.out.println((arr[i]));  
            }  
        } catch (ArrayIndexOutOfBoundsException e) {  
            System.out.println(e);  
            System.out.println("예외 발생");  
        } finally {  
            System.out.println("오류 발생과 상관없이 무조건 실행");  
        }  
        System.out.println("예외 처리로 종료 없이 마지막까지 실행됨");  
    }  
}
```

> **실행 결과**

```plaintext
0
1
2
3
4
java.lang.ArrayIndexOutOfBoundsException: Index 5 out of bounds for length 5
예외 발생
오류 발생과 상관없이 무조건 실행
예외 처리로 종료 없이 마지막까지 실행됨
```

`try-catch`문이 없다면 마지막 출력이 실행되지 않고 프로그램이 종료되지만 try-catch로 예외 처리하면 마지막까지 실행된다.

for문의 `i <= 5` 부분 때문에 오류가 발생한다. 이 부분에서 발생한 오류가 `catch`에 의해 처리되고 프로그램 강제 종료 없이 마지막까지 실행된다.

오류가 발생하는 부분을 `i < 5`로 수정해 `catch`문을 그냥 통과하게 바꾸더라도 `finally`블럭의 내용은 항상 실행된다.

---

### throw

프로그램에 실제 오류가 발생하지 않더라도 `throw`키워드를 사용해 강제로 예외를 발생시킬 수 있다.
아래는 실제로 `ArithmeticException`이 발생할 상황이 아닌데 강제로 발생시키는 예시이다.


```java
public class Throw {  
    public static void main(String[] args) {  
        try {  
            System.out.println("Throw Error!!");  
            throw new ArithmeticException();  
        } catch (ArithmeticException e) {  
            System.out.println("Error Confirmed");  
            e.printStackTrace();
        }  
    }  
}
```


>  **실행 결과**
```diff
Throw Error!!
Error Confirmed
- java.lang.ArithmeticException
-    at assignment.exception.Throw.main(Throw.java:8)
```

의도한 대로 `ArithmeticException`이 발생한 모습을 볼 수 있다.

---

### throws

예외를 발생한 해당 메서드에서 처리하지 않고 미룬 후에 메서드를 호출하여 사용하는 부분에서 예외 처리 하는 방법이다.

위의 _thorw_ 랑 _s_ 한 글자 차이지만  다른 기능이니까 헷갈리지 말자.

`throws`는 **메서드 선언부**에 작성한다. 이 메서드를 실행 중 예외가 발생할 수 있으니 이를 호출하는 쪽에서 대비하라고 알리는 역할이다. 여러 예외를 동시에 던질 수도 있다.

> **throws 사용법**
> ```java
> public void throwsErr() throws IOException, SQLException { 
> 	... 
> }
> ```



예시 코드로 이해해보자.

```java 
public class Throws {  
    // throws가 없는 메서드 
    // 메서드마다 예외 처리를 해야 한다
    public static void throwError() {  
        try {  
            System.out.println("throwError 실행");  
            throw new ArithmeticException();  
        } catch (ArithmeticException e) {  
            System.out.println(e.toString());  
        }  
    }  
  
    // throws 사용해 일어날 수 있는 예외를 호출부로 던지기
    public static void throwsError1() throws NullPointerException {  
        System.out.println("throwsError 1 실행");  
        throw new NullPointerException("Error!");  
    }  
  
    public static void throwsError2() throws IOException {  
        System.out.println("throwsError 2 실행");  
        throw new IOException("Error!!");  
    }  
    
    // throws로 경고받은 메서드들을 해당 메서드를 호출하는 main에서 처리  
    public static void main(String[] args) {  
        try {  
            throwError();  
            throwsError1();  
            throwsError2();  
        } catch (IOException | NullPointerException e) {  
            System.out.println(e.toString());  
        }  
    }  
}
```

> **실행 결과**
```text
throwError 실행
java.lang.ArithmeticException
throwsError 1 실행
java.lang.NullPointerException: Error!
```

가장 위의 메서드인 `throwError`는 메서드 내부에서 자체적으로 예외를 처리하고 있다. 모든 메서드에서 이렇게 예외를 처리한다면 코드가 길어지고 작성도 귀찮을 수 있다.

`throwsError1`과 `throwsError2`를 보면 **`throws`** 키워드를 사용해 발생할 수 있는 예외에 대해 알려주고 있다.

이 메서드들을 호출하는 `main` 메서드에서 이 예외들에 대한 처리를 `try - catch`로 해 주었다.

실행 결과를 살펴보면 메서드에서 예외 처리해 준 `throw()`가 자체적으로 예외 처리해 실행된 뒤에 `throwsError1`이 실행되면서 main에서 설정한 예외 처리가 작동한다. main의 `try-catch`문이 여기서 catch로 점프하면서 `throwsError2()`는 실행되지 않고 종료된 것을 알 수 있다.


> **throws 정리**
> - `throws`를 사용해서 예외를 메서드 호출부에서 처리할 수 있다.
> - 각 메서드에 try-catch로 작성하는것과 다르게 메서드를 모두 실행하지 않고 try-catch문이 작동할 때 종료되는 것도 알고 있자.
> - `throw`, `throws` 착각하지 말기!