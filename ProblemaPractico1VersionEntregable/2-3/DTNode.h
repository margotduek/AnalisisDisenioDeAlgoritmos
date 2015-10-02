

template <class T>
class DTNode{
    bool hasSmall = false;
    bool hasHigh = false;
    bool full = false;
    T* smaller = nullptr;
    T* higher = nullptr;
    T* tempMiddle = nullptr;
    DTNode<T>* parent = nullptr;
    DTNode<T>* leftChild = nullptr;
    DTNode<T>* middleChild = nullptr;
    DTNode<T>* rightChild = nullptr;
    DTNode<T>* tempChild = nullptr;
public:
    DTNode<T>():leftChild(nullptr),middleChild(nullptr),rightChild(nullptr),parent(nullptr),smaller(nullptr),higher(nullptr),tempMiddle(nullptr),tempChild(nullptr){}
    DTNode(T _smaller){
        smaller = new T(_smaller);
        hasSmall = true;
    }
    virtual ~DTNode(){
        leftChild = middleChild = rightChild = parent = tempChild = nullptr;
        smaller = higher = nullptr;
    }

    DTNode<T>* getTempChild(){
        return tempChild;
    }

    void setTempChild(DTNode<T>* node){
        tempChild = node;
    }

    T getTempMiddle(){
        return *tempMiddle;
    }

    void deleteTempMiddle(){
        if(tempMiddle){
            tempMiddle = nullptr;
        }
    }

    void setTempMiddle(T _value){
        if(tempMiddle == nullptr){
            tempMiddle = new T(_value);
        }
        else{
            *tempMiddle = _value;
        }
    }

    bool hasTempMiddle(){
        if(tempMiddle)
            return true;
        else
            return false;
    }

    void setLower(T _value){
        if(smaller!=nullptr){
            *smaller = _value;
        }
        else{
            smaller = new T(_value);
        }
    }

    void setHigher(T _value){
        if(higher!=nullptr){
            *higher = _value;
        }
        else{
            higher = new T(_value);
        }
    }

    T getLower(){
        return *smaller;
    }

    T getHigher(){
        return *higher;
    }

    bool isFull(){
        if(higher && smaller)
            return true;
        return false;
    }

    bool has3Keys(){
        return higher && smaller && tempMiddle;
    }

    void setValue(T _value){
        if(!smaller){
            smaller = new T(_value);
        }
        else{
            if(_value >= *smaller){
                if(!higher){
                    higher = new T(_value);
                }
            }
            else if(_value < *smaller){
                higher = new T(*smaller);
                *smaller = _value;
            }
        }
    }

    void deleteAllKeys(){
        if(smaller)
            smaller = nullptr;
        if(higher)
            higher = nullptr;
    }

    void setMiddleValue(T _value){
        if(higher && smaller){
            if(!tempMiddle){
                tempMiddle = new T(_value);
                if(_value < *smaller){
                    *tempMiddle = *smaller;
                    *smaller = _value;
                }
                else if(_value >= *smaller && _value <= *higher){
                    *tempMiddle = _value;
                }
                else{
                    *tempMiddle = *higher;
                    *higher = _value;
                }
            }
            else{
                if(_value < *smaller){
                    *tempMiddle = *smaller;
                    *smaller = _value;
                }
                else if(_value >= *smaller && _value <= *higher){
                    *tempMiddle = _value;
                }
                else{
                    *tempMiddle = *higher;
                    *higher = _value;
                }
            }
        }
    }

    void deleteHigher(){
        if(higher){
            higher = nullptr;
        }
    }

    void deleteLower(){
        if(smaller)
            smaller = nullptr;
    }

    void swapHigherToLower(){
        if(!smaller)
            smaller = new T(*higher);
        else
            *smaller = *higher;
        higher = nullptr;
    }


    bool hasLower(){
        if(smaller==nullptr)
            return false;
        else
            return true;
    }
    bool hasHigher(){
        if(higher==nullptr)
            return false;
        else
            return true;
    }

    bool hasNoKeys(){
        return !smaller && !higher;
    }

    DTNode<T> * getLeft() const { return leftChild; }
    void setLeft(DTNode<T> * value) { leftChild = value; }

    DTNode<T> * getRight() const { return rightChild; }
    void setRight(DTNode<T> * value) { rightChild = value; }

    DTNode<T> * getMiddle() const { return middleChild; }
    void setMiddle(DTNode<T> * value) { middleChild = value; }

    DTNode<T> * getParent() const { return parent; }
    void setParent(DTNode<T> * value) { parent = value; }
};
