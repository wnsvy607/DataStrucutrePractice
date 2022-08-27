var BinaryTree = /** @class */ (function () {
    function BinaryTree(data) {
        if (data === void 0) { data = NaN; }
        this.data = data;
    }
    BinaryTree.prototype.isEmpty = function () {
        if (this.data === NaN)
            return true;
        else
            return false;
    };
    BinaryTree.prototype.SetLeftSubTree = function (LChild) {
        this.left = LChild;
    };
    BinaryTree.prototype.SetRightSubTree = function (RChild) {
        this.right = RChild;
    };
    BinaryTree.prototype.GetLChild = function () {
        return this.left;
    };
    BinaryTree.prototype.GetRChild = function () {
        return this.right;
    };
    BinaryTree.prototype.GetData = function () {
        return this.data;
    };
    BinaryTree.prototype.SetData = function (data) {
        this.data = data;
    };
    //중위 순회
    BinaryTree.prototype.inOrderPrint = function () {
        if (this.GetLChild() !== undefined) {
            this.GetLChild().inOrderPrint();
        }
        process.stdout.write(this.GetData() + " ");
        if (this.GetRChild() !== undefined) {
            this.GetRChild().inOrderPrint();
        }
    };
    //전위 순회
    BinaryTree.prototype.preOrderPrint = function () {
        process.stdout.write(this.GetData() + " ");
        if (this.GetLChild() !== undefined) {
            this.GetLChild().preOrderPrint();
        }
        if (this.GetRChild() !== undefined) {
            this.GetRChild().preOrderPrint();
        }
    };
    //후위 순회
    BinaryTree.prototype.postOrderPrint = function () {
        if (this.GetLChild() !== undefined) {
            this.GetLChild().postOrderPrint();
        }
        if (this.GetRChild() !== undefined) {
            this.GetRChild().postOrderPrint();
        }
        process.stdout.write(this.GetData() + " ");
    };
    return BinaryTree;
}());
var bt1 = new BinaryTree(1);
var bt2 = new BinaryTree(2);
var bt3 = new BinaryTree(3);
var bt4 = new BinaryTree(4);
var bt5 = new BinaryTree(5);
var bt6 = new BinaryTree(6);
var bt7 = new BinaryTree(7);
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
