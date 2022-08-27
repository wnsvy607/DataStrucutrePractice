class Node{
    constructor(data){
        this.data = data;
        this.next = null;
    }
}

class Queue{
 
    constructor(){
        this.front = null;
        this.rear = null;
    }

    isEmpty(){
        return this.front == null;
    }

    enqueue(data){
        const newNode = new Node(data);
        if(this.isEmpty()){
            this.front = newNode;
        } else {
            this.rear.next = newNode;
        }
        this.rear = newNode;
    }

    dequeue(){
        if(this.isEmpty()){
            console.log("Queue underflow error");
            return;
        }
        let val = this.front.data;
        this.front  = this.front.next;
        return val;
    }

    peek(){
        if(this.isEmpty()){
            console.log("Queue underflow error");
            return;
        }
        return this.front.data;
    }

}


const que = new Queue();

for(let i = 0; i <10 ; i++ ){
    que.enqueue(i);
}

for(let i = 0; i <10 ; i++ ){
    let number = que.dequeue();
    console.log(number);
}