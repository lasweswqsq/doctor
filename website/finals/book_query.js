window.alert('welcome to this library management system');
$(function(){
    $("#query_submit").on("click", function(e){
        var query = $("#query_input").val();

        $.get("http://127.0.0.1:8000/items/" + query,function(data,status){
            //        IP        端口号
            //请求了"http://127.0.0.1:8000/items/" + query的地址
            alert("数据: " + data + "\n状态: " + status);
            for(var i=0;i<data.length;i++){
                //循环遍历data数组，并将数据添加到表格中
                var statusDesc= data[i][6]==0?"未借出":"已借出"; //判断书籍状态，0为未借出，1为已借出
                addRow(data[i][0], data[i][1], data[i][2], data[i][3], data[i][4], data[i][5], statusDesc);
            }

        })
    })
    $("#user_submit").on("click", function(e){
        var user = $("#user_input").val();
        var password = $("#password_input").val();
        $.post("http://127.0.0.1:8000/users/" + user + "/" + password, function(data, status) {
            alert("数据: " + data + "\n状态: " + status);
            if(data == 1){
                //location.href = "workout.html";
                var container = document.getElementById("buttonContainer1");
                // 使用innerHTML添加按钮
                container.innerHTML = '<button class="btn" id="workout_button">查询图书</button>';
                var container = document.getElementById("buttonContainer2");
                // 使用innerHTML添加按钮
                container.innerHTML = '<button class="btn" id="insert_button">录入图书</button>';
                var container = document.getElementById("buttonContainer3");
                // 使用innerHTML添加按钮
                container.innerHTML = '<button class="btn" id="update_button">修改图书</button>';
                var container = document.getElementById("buttonContainer4");
                // 使用innerHTML添加按钮
                container.innerHTML = '<button class="btn" id="delete_button">删除图书</button>';
                $("#workout_button").on("click", function(e){
                    location.href = "workout.html";
                })
                $("#insert_button").on("click", function(e){
                    location.href = "insert.html";
                })             
                $("#update_button").on("click", function(e){
                    location.href = "update.html";
                })
                $("#delete_button").on("click", function(e){
                    location.href = "delete.html";
                })
            }else{
                alert("用户名或密码错误");
            }
        })
    })
    $("#book_submit").on("click", function(e){
        var id = $("#id").val();
        var title = $("#title").val();
        var author = $("#author").val();
        var time = $("#time").val();
        var create_time = $("#create_time").val();
        var creator = $("#creator").val();
        var status = $("#status").val();
        $.post("http://127.0.0.1:8000/items/add/" + id + "/" + title + "/" + author + "/" + time + "/" + create_time + "/" + creator + "/" + status, function(data, status) {
            alert("数据: " + data + "\n状态: " + status);
        })
    })
    
})


function addRow(id, title, author,time,create_time,creator,status) {
    var table = document.getElementById("book_table");
    var newRow = table.insertRow(-1); // 在表格末尾添加新行
    var cell1 = newRow.insertCell(0); // 在新行中插入第一个单元格
    var cell2 = newRow.insertCell(1); // 在新行中插入第二个单元格
    var cell3 = newRow.insertCell(2); // 在新行中插入第三个单元格
    var cell4 = newRow.insertCell(3); // 在新行中插入第一个单元格
    var cell5 = newRow.insertCell(4); // 在新行中插入第二个单元格
    var cell6 = newRow.insertCell(5); // 在新行中插入第三个单元格
    var cell7 = newRow.insertCell(6);
    var cell8 = newRow.insertCell(7);
    cell1.textContent = id; // 设置单元格内容
    cell2.textContent = title;
    cell3.textContent = author;
    cell4.textContent = time; // 设置单元格内容
    cell5.textContent = create_time;
    cell6.textContent = creator;
    cell7.textContent = status;
    if(status == '已借出'){
        cell8.innerHTML = "<button onclick='retu(" + id + ")'>还书</button>"; // 设置单元格内容
    }else{
        cell8.innerHTML = "<button onclick='borrow(" + id + ")'>借书</button>"; // 设置单元格内容
    }
}



function borrow(id) {
    $.post("http://127.0.0.1:8000/items/borrow/" + id, function(data, status) {
        alert("借阅成功");
    });
}

function retu(id) {
    $.post("http://127.0.0.1:8000/items/return/" + id, function(data, status) {
        alert("还书成功");
    });
}