class BinaryTree {
    data :number;
    left :BinaryTree;
    right :BinaryTree;
    constructor(data :number = NaN){
        this.data = data;
    }

    isEmpty() :boolean{
        if(this.data === NaN)
            return true;
        else
            return false;
    }

    SetLeftSubTree(LChild :BinaryTree){
         this.left = LChild;
    }

    SetRightSubTree(RChild :BinaryTree){
         this.right = RChild;
    }

    GetLChild() :BinaryTree{
        return this.left;
    }

    GetRChild() :BinaryTree{
        return this.right;
    }

    GetData() :number{
        return this.data;
    }

    SetData(data :number){
        this.data = data;
    }

    //중위 순회
    inOrderPrint(){

        if(this.GetLChild() !== undefined){
            this.GetLChild().inOrderPrint();
        }
        document.write(this.GetData() + " ")
        if(this.GetRChild() !== undefined){
            this.GetRChild().inOrderPrint();
        }
        
    }

    //전위 순회
    preOrderPrint(){       

            document.write(this.GetData() + " ");
            if(this.GetLChild() !== undefined){
                this.GetLChild().preOrderPrint();
            }
            if(this.GetRChild() !== undefined){
                this.GetRChild().preOrderPrint();
            }
    }

    //후위 순회
    postOrderPrint(){

        if(this.GetLChild() !== undefined){
            this.GetLChild().postOrderPrint();
        }
        if(this.GetRChild() !== undefined){
            this.GetRChild().postOrderPrint();
        }
        document.write(this.GetData() + " ");
        
    }
}



const bt1 = new BinaryTree(1);
const bt2 = new BinaryTree(2);
const bt3 = new BinaryTree(3);
const bt4 = new BinaryTree(4);
const bt5 = new BinaryTree(5);
const bt6 = new BinaryTree(6);
const bt7 = new BinaryTree(7);

bt1.SetLeftSubTree(bt2);
bt1.SetRightSubTree(bt3);
bt2.SetLeftSubTree(bt4);
bt2.SetRightSubTree(bt5);
bt3.SetLeftSubTree(bt6);
bt3.SetRightSubTree(bt7);

bt1.inOrderPrint();
console.log("\n");
bt1.postOrderPrint();
console.log("\n");
bt1.preOrderPrint();
