# TIL_26/02/11 - @Override annotation이 뭘까?

클래스 상속에 대해 학습하고 추상 메소드의 예제 코드를 작성하며 실습하던 중 IDE가 자동으로 생성한 추상 메소드 구현부 위에 모두 `@Override` 키워드가 붙어있었다. 이건 무엇이고 어떤 역할일까?

## @

우선 Override 라는 키워드 앞에 붙은 `@` = Annotation에 대해 알아보자

**어노테이션(Annotation)**

Java 1.5 버전부터 추가된 어노테이션은 주석처럼 정보를 제공하기 위한 코드이다. 영단어 annotation 자체가 주석이라는 뜻을 가진다.

그럼 `//`랑 같은건가? 싶지만 그건 아니다! `// 주석주석`처럼 작성해서 우리가 읽고 내용을 파악하는데 도움을 주는 주석과 달리 어노테이션은 컴파일러에게 알려주는 기능을 한다. 
- 컴파일러가 코드 문법 에러를 체크할 수 있도록 정보를 제공하고
- 코드 자동 생성을 돕기도 한다
자바가 기본적으로 제공하는 표준 어노테이션에는 `@Override`, `@Deprecated` 등이 있다.

## @Override

@Override 어노테이션은 문법적으로 필수적인 사항은 아니지만 여러 장점이 있어 사용하는게 권장된다.

1. **컴파일 타임 체크**
	개발자가 부모 클래스 메소드를 재정의할 때, 실수로 메소드 이름을 잘못 적거나 매개변수 타입을 다르게 작성한다면?
	- **Annotation이 없을 때**: 컴파일러가 새로운 메소드 추가한 것으로 인식해 오류 없이 넘어간다.
	  물론 프로그램 실행한 뒤에는 의도대로 작동하지 않아 어디가 문제인지 찾기가 어려운 문제가 생긴다.
	- **Annotation이 있을 때**: 컴파일러가 이 메소드는 부모의 추상메소드를 반드시 재정의해야 한다는 내용을 인지한다. 부모 클래스에 일치하는 메소드가 없다면 컴파일 에러를 발생시켜 개발자가 실수한 내용을 바로 잡아낸다.

2. **코드 가독성 향상 & 의도 명시**
	`@Override`가 붙어 있으면 해당 코드를 읽는 다른 사람이 (혹은 미래의 내가) 상속받은 클래스, 인터페이스에서 온 메소드임을 바로 알 수 있다.

3. **유지보수와 리팩토링의 안전성**
	부모 클래스의 메소드 시그니쳐(이름이나 매개변수)가 변경되었을 때 유용하다.
	- 부모 클래스의 메소드 이름이 바뀌었는데 자식 클래스에서 `@Override`를 사용중이라면, 자식 클래스의 해당 부분에서 컴파일 에러가 바로 발생한다.

---

### 참고한 글
- [wikipedia - Java annotation](https://en.wikipedia.org/wiki/Java_annotation)
- [Meghna Dwivedi - Java @Override annotation](https://meghnadwivedi.medium.com/java-override-annotatio-b602708d2d5f)
- [stack overflow - When do you use Java's @Override annotation and why? ](https://stackoverflow.com/questions/94361/when-do-you-use-javas-override-annotation-and-why)