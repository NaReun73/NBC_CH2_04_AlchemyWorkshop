# [4번 과제] C++ Summary - 연금술 공방 관리 시스템 구현
---

<aside>


이번 과제는 기본으로 코드를 제공해드립니다.
아래의 기존 코드를 분석하고 구조를 유지한 채로 기능을 수정하거나 추가 해보세요!

- [코드스니펫] 물약 공방 관리 프로그램
    
    ```cpp
    #include <iostream>
    #include <vector>
    #include <string>
    
    // PotionRecipe 클래스: 재료 목록을 vector<string>으로 변경
    class PotionRecipe {
    public:
        std::string potionName;
        std::vector<std::string> ingredients; // 단일 재료에서 재료 '목록'으로 변경
    
        // 생성자: 재료 목록을 받아 초기화하도록 수정
        PotionRecipe(const std::string& name, const std::vector<std::string>& ingredients)
            : potionName(name), ingredients(ingredients) {}
    };
    
    // AlchemyWorkshop 클래스: 레시피 목록을 관리
    class AlchemyWorkshop {
    private:
        std::vector<PotionRecipe> recipes;
    
    public:
        // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
        void addRecipe(const std::string& name, const std::vector<std::string>& ingredients) {
            recipes.push_back(PotionRecipe(name, ingredients));
            std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << std::endl;
        }
    
        // 모든 레시피 출력 메서드
        void displayAllRecipes() const {
            if (recipes.empty()) {
                std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
                return;
            }
    
            std::cout << "\n--- [ 전체 레시피 목록 ] ---" << std::endl;
            for (size_t i = 0; i < recipes.size(); ++i) {
                std::cout << "- 물약 이름: " << recipes[i].potionName << std::endl;
                std::cout << "  > 필요 재료: ";
                
                // 재료 목록을 순회하며 출력
                for (size_t j = 0; j < recipes[i].ingredients.size(); ++j) {
                    std::cout << recipes[i].ingredients[j];
                    // 마지막 재료가 아니면 쉼표로 구분
                    if (j < recipes[i].ingredients.size() - 1) {
                        std::cout << ", ";
                    }
                }
                std::cout << std::endl;
            }
            std::cout << "---------------------------\n";
        }
    };
    
    int main() {
        AlchemyWorkshop myWorkshop;
    
        while (true) {
            std::cout << "⚗️ 연금술 공방 관리 시스템" << std::endl;
            std::cout << "1. 레시피 추가" << std::endl;
            std::cout << "2. 모든 레시피 출력" << std::endl;
            std::cout << "3. 종료" << std::endl;
            std::cout << "선택: ";
    
            int choice;
            std::cin >> choice;
    
            if (std::cin.fail()) {
                std::cout << "잘못된 입력입니다. 숫자를 입력해주세요." << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }
    
            if (choice == 1) {
                std::string name;
                std::cout << "물약 이름: ";
                std::cin.ignore(10000, '\n');
                std::getline(std::cin, name);
    
                // 여러 재료를 입력받기 위한 로직
                std::vector<std::string> ingredients_input;
                std::string ingredient;
                std::cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << std::endl;
                
                while (true) {
                    std::cout << "재료 입력: ";
                    std::getline(std::cin, ingredient);
                    
                    // 사용자가 '끝'을 입력하면 재료 입력 종료
                    if (ingredient == "끝") {
                        break;
                    }
                    ingredients_input.push_back(ingredient);
                }
    
                // 입력받은 재료가 하나 이상 있을 때만 레시피 추가
                if (!ingredients_input.empty()) {
                     myWorkshop.addRecipe(name, ingredients_input);
                } else {
                    std::cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << std::endl;
                }
    
            } else if (choice == 2) {
                myWorkshop.displayAllRecipes();
    
            } else if (choice == 3) {
                std::cout << "공방 문을 닫습니다..." << std::endl;
                break;
    
            } else {
                std::cout << "잘못된 선택입니다. 다시 시도하세요." << std::endl;
            }
        }
    
        return 0;
    }
    ```
    
</aside>

**1단계 : 제공된 연금술 공방의 물약 관리 프로그램 코드 분석**

- 실제 현업을 하다보면 처음부터 코드를 구현하는 상황보다는, 이미 누군가 구현한 코드를 파악하고 이를 수정하거나 기능을 추가해야 하는 경우가 많습니다.
- 아래 3가지를 꼭 고려하면서 기존 코드를 분석해보세요.
    - 어떤 의도로 이 코드를 구현했을까?
    - 수정을 해야 한다면, 기존 코드의 수정을 최소화 할 수 있는 방안이 있을까?
    - 객체지향 프로그래밍 언어라면 SOLID 원칙을 잘 준수하고 있나?

**2단계 : 제공된 코드를 활용해서 간단한 물약 이름 검색 기능을 추가**

- 필수기능 가이드를 참고해주세요!

**3단계 : 물약 지급/공병 반환 기능을 추가**

- 도전 기능 가이드를 참고해주세요!


## 필수 기능 가이드

---

<aside>

### 필수 구현 기능

- 👀 **전체적인 게임 구조 확인하기**
    - 전체적인 구조를 그리면 아래와 같습니다.
        - 필수 기능 구현 완료
        - `AlchemyWorkshop` 클래스에 검색 관련 메서드가 추가
    - 꼭 이대로 구현할 필요는 없습니다. 창의력을 발휘해보세요!
    
    ![image.png](attachment:aecdd14f-aff7-470b-b309-265f069aa195:image.png)
    

---

1. 기존 코드 분석하기
    - [x]  어떤 의도로 이 코드를 구현했을까?
    - [x]  수정을 해야 한다면, 기존 코드의 수정을 최소화 할 수 있는 방안이 있을까?
    - [x]  기존 코드는 SOLID 원칙을 잘 준수하고 있나?

---

1. 기존 연금술 공방 관리 시스템에 검색 기능을 추가합니다.
    - [x]  **물약 이름**으로 검색이 가능하게 하기
        - 물약 이름이 동일한 경우는 없다고 가정합니다.
    - [x]  **재료**로 검색이 가능하게 하기
        - 특정 재료가 포함된 모든 레시피를 찾을 수 있어야 합니다.
</aside>

## 도전 기능 가이드

---

<aside>

### 도전 구현 기능

- 👀 **게임 구조 확인하기**
    
    도전 기능이 추가된 `AlchemyWorkshop` 클래스의 구조는 다음과 같습니다.
    
    ![image.png](attachment:2617c125-f82e-48ef-be8d-7b10b5603f1e:image.png)
    

---

1. **초기 재고 설정**
    - [x]  자동 초기 재고 지급
        - 새로운 레시피가 추가되면 해당 물약의 재고를 기본 3개로 설정하세요.

---

1. **물약 찾기 및 지급**
    - [ ]  물약 이름과 물약에 사용되는 재료 이름으로 창고를 검색하는 기능을 만드세요.
        - 예) 물약 ‘간장계란밥’을 검색할 때, 이름인 ‘간장계란밥’을 입력해도, ‘간장’, ‘계란’,’참기름’ 등 재료를 입력해도 검색이 되어야 합니다.
    - [ ]  재고가 1개 이상일 때만 모험가에게 줄 수 있고,
    주면 재고가 1 감소합니다.

---

1. **공병 반환하기**
    - [ ]  모험가에게 물약을 다시 돌려받는 기능을 만드세요.
    - [ ]  돌려받으면 재고가 1 증가합니다.

---

1. **창고 최대치(MAX) 제한**
    - [ ]  반환받을 때 이미 3개라면, 더 이상 늘어나지 않도록 예외 처리를 해주세요.
        - 모든 물약의 최대 재고는 3개입니다.
</aside>




<aside>

# 기존 코드 분석하기

---

<aside>

## 어떤 의도로 이 코드를 구현했을까?

---

- 연금술 공방이 있고 포션의 레시피가 있습니다.
- 연금술 공방에서 포션의 레시피를 추가할 수 있습니다.
- 포션의 레시피는 이름과 재료들을 가지고 있습니다.
    - 재료는 한 개 이상이어야 합니다.
- 연금술 공방에서 모든 포션의 레시피(이름, 재료들)를 볼 수 있습니다.
</aside>

<aside>

## 수정을 해야 한다면, 기존 코드의 수정을 최소화 할 수 있는 방안이 있을까?

---

기존 코드의 수정을 최소화 할 방안을 모르겠어서 검색을 통해 알아본 결과입니다.

<aside>

### `std::vector` 복사 비용 줄이기 (`const &`와 `std::move`)

---

`addRecipe` 함수는 `ingredients_input`을 인자로 받을 때 한 번 복사하고, `PotionRecipe` 생성자에서 또 한 번 복사합니다. 재료가 많아지면 성능 낭비가 생길 수 도 있습니다.

- 생성자에서 `std::move`를 사용하면 복사 대신 '소유권 이전'을 수행해 훨씬 빨라집니다.
- **`std::move`**
    
    **소유권 이전 (Transfer of Ownership) 도구**
    
    데이터가 아주 큰 객체 (수만 개의 아이템이 든 `std::vector`)를 다룰 때 좋습니다.
    
    **복사 시** 수만 개의 아이템을 담을 새 메모리에 할당하고 데이터를 일일이 옮기지만,
    
    **이동 시** 새 메모리 할당 없이, 기존 데이터가 들어있는 **메모리 주소값(포인터)**만 넘겨줍니다.
    
    `std::move(a)` 를 쓴 직후의 원본 변수는 **텅 빈 상태**가 됩니다. 이 후에 `a`를 사용하면 안됩니다.
    
    std::move 는 **이 변수가 더 이상 쓸 일이 없다고 확신**할 때만 사용해야 합니다.
    
- 수정 코드
    
    ```cpp
    // PotionRecipe 생성자만 살짝 수정
    PotionRecipe(const std::string name, std::vector<std::string> ingredients)
        : potionName(std::move(name)), ingredients(std::move(ingredients)) {}
    ```
    
    - 함수의 매개변수 `name`과 `ing`는 이미 메모리에 들어와 있습니다.
    - 클래스 멤버 변수(`potionName`, `ingredients`)에 넣을 때, 또 복사본을 만들지 말고 **매개변수가 들고 있는 데이터를 그대로 뺏어오라고** 명령하는 것입니다.
    - 함수가 끝나면 어차피 사라질 매개변수들이니 더 이상 쓸 일이 없습니다.
</aside>

<aside>

### 출력 로직 최적화 (범위 기반 for문)

---

객체가 크거나, 복사 비용을 줄이고 싶을 때 사용합니다. 값을 바꾸지 않겠다는 것을 명시합니다.

`displayAllRecipes`의 이중 for문은 인덱스(`i`, `j`)를 사용하고 있습니다.

범위 기반 for문을 사용해 인덱스 계산 없이 객체에 바로 접근합니다.

| **특징** | **기존 for문 (Index 기반)** | **범위 기반 for문** |
| --- | --- | --- |
| **코드 길이** | 길고 복잡함 (`i = 0; i < n...`) | 매우 간결함 |
| **안전성** | 인덱스 실수(Out of bounds) 위험 | 컨테이너 끝을 알아서 계산하므로 안전 |
| **유연성** | 특정 인덱스 건너뛰기 가능 | 무조건 처음부터 끝까지 순회 |
- 수정 코드
    
    ```cpp
    void displayAllRecipes() const
    {
        if (recipes.empty())
        { 
    	    std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
    			return;
        }
    
        for (const auto& recipe : recipes) // Index 대신 auto 사용
        { 
            std::cout << "- 물약 이름: " << recipe.potionName << std::endl;
            std::cout << "  > 필요 재료: ";
            for (size_t i = 0; i < recipe.ingredients.size(); ++i)
            {
                std::cout << recipe.ingredients[i] << (i < recipe.ingredients.size() - 1 ? ", " : "");
            }
            std::cout << std::endl;
        }
    }
    ```
    
</aside>

<aside>

### 입력 버퍼 문제 방지 (`cin.ignore`)

---

`main` 함수에서 `choice` 를 입력받은 후, `if(choice == 1)` 내부에서만 하지말고 입력 받은 직후 공통으로 처리하는 것이 좋습니다.

- `cin.ignore(a, '\n')`
    
    입력 버퍼에 남아있는 찌꺼기를 청소하는 함수
    
    C++에서 입력을 받을 때, 키보드로 치는 모든 내용은 입력 버퍼라는 임시 저장소에 쌓입니다. 이 버퍼를 관리하지 않으면 원치 않는 값이 다음 입력에 끼어들수도 있습니다.
    
    첫 번째 인자 (a ) :  a만큼 글자를 무시
    
    두 번째 인자 (’\n’) : 엔터 (\n)를 만나면, 엔터까지만 지우고 멈춤
    
- `std::cin >>` 다음에 `std::getline` 을 쓸 때 무조건 필수적으로 씁니다.
    - `std::getline`  은 엔터 키를 칠 때까지 한 줄을 통째로 읽어오는 함수
    - 공백을 포함하여 엔터가 나오기 전까지의 모든 문자를 한꺼번에 읽어옵니다.
    - `std::cin` 은 공백, 탭, 엔터를 만나면 그 전까지만 읽고 멈춥니다.
        - 나머지는 버퍼에 남겨둡니다.
        - Health Potion 이라 입력하면 Health 까지만 읽고 Potion은 버퍼에 남겨둡니다.
- 수정 코드
    
    ```cpp
    int choice;
    std::cin >> choice;
    std::cin.ignore(10000, '\n');
    ```
    
</aside>

</aside>

<aside>

## 기존 코드는 SOLID 원칙을 잘 준수하고 있나?

---

### 단일 책임 원칙

각 클래스는 하나의 책임만 가져야 한다는 원칙입니다.

AlchemyWorkshop 은 레시피 추가와 출력 두 가지 책임을 가지고 있습니다.

### 개방 폐쇄 원칙

확장에는 열려 있어야 하고, 수정에는 닫혀있어야 한다는 개념입니다.

포션 레시피 말고 다른 레시피가 추가되면 addRecipe() 함수나 displayAllRecipes() 함수를 수정을 해야합니다.

### 의존 역전 원칙

고 수준 모듈은 저 수준에 직접 의존하는 것이 아니라, 두 모듈 모두 추상화에 의존해야 합니다.

AlchemyWorkshop 클래스는 구체적인 PotionRecipe 클래스에 강하게 결합되어 있습니다.

</aside>

</aside>