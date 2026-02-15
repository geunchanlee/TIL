# TIL 26/02/12 - Java Inner Class

## 내부 클래스

내부 클래스: 클래스 내부에 선언한 클래스

### 인스턴스 내부 클래스

인스턴스 변수를 선언할 때와 같은 위치에 선언한다. (멤버변수 선언하는 곳에서 내부 클래스를 선언)

- 외부 클래스 내부에서만 생성하여 사용하는 객체를 선언할 때 사용한다.
- 외부 클래스가 먼저 생성되어야 사용할 수 있고, 외부 클래스의 메서드가 호출될 때 사용 가능하다.
	- 외부 클래스가 인스턴스화 되었을 때만 사용할 수 있기 때문에 정적 메서드를 정의할 수 없다.


### 정적 내부 클래스

인스턴스 내부 클래스처럼 외부 클래스의 멤버변수와 같은 위치에 정의하고 `static` 예약어를 사용한다.
내부 클래스가 외부 클래스의 생성과 무관하게 사용할 수 있어야 하면서 정적 변수도 사용해야 할 때 사용한다.


### 지역 내부 클래스

지역 변수처럼 메서드 안에 클래스를 정의해 사용 => 메서드 안에서만 사용 가능하다.


### 익명 클래스

이름이 없는 클래스. 한 번만 사용하고 버려지는 일회용 클래스이다.

끝내는 중괄호 뒤에 **세미콜론 ;** 을 넣어준다.

인스턴스변수를 선언하고 클래스를 생성해 대입한 다음 부모 클래스의 메서드를 오버라이딩한다. 

기존 부모 클래스를 상속하는 자식 클래스에서는 새로 메서드를 정의해 만들 수 있지만 익명 클래스 방식으로 선언하면 오버라이딩한 메서드만 사용할 수 있고 새로 정의한 메서드를 외부에서 사용할 수 없다.


```java
// 익명 클래스 이해용 코드  

// 기존 부모 클래스와 이를 상속받은 자식 클래스  
class Parent {  
    public void whoAmI(){  
        System.out.println("Parent Class");  
    }  
}  
  
class Child extends Parent {  
    @Override  
    public void whoAmI() {  
        System.out.println("Child Class");  
    }  
}  

// 메인
public class AnonymousClass {  
    public static void main(String[] args) {  
    
        Parent parent = new Parent();  
        Child child = new Child();
  
        parent.whoAmI();  
        child.whoAmI();  
  
        // 익명클래스  
        // 클래스 정의와 객체화를 동시에 처리하는 일회용 클래스  
        Parent anonymous = new Parent() {  
            @Override  
            public void whoAmI(){  
                System.out.println("Anonymous Class");  
            }  
        }; // 익명 클래스 끝에 세미콜론 붙이기!  
  
        // 익명클래스 사용  
        anonymous.whoAmI();  
    }  
}
```

> 실행결과
```Plain Text
Parent Class
Child Class
Anonymous Class
```


