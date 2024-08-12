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
                $("#workout_button").on("click", function(e){
                    location.href = "workout.html";
                })
                $("#insert_button").on("click", function(e){
                    location.href = "insert.html";
                })             
            }else{
                alert("用户名或密码错误");
            }
        })
    })
    $("#book_submit").on("click", function(e){
        var title = $("#title").val();
        var author = $("#author").val();
        var time = $("#time").val();
        var creator = $("#creator").val();
        $.post(`http://127.0.0.1:8000/items/add/${title}/${author}/${time}/${creator}`, function(data, status) {
            alert("提交成功");
            addRow1("——", title, author, time, "now", creator, "未借出");
        })
    })
    $("#book_update").on("click", function(e){
        //假设 URL 是:https://example.com/?param1=value1&param2=value2
        const currentURL = window.location.href;
        //1.创建一个 URL 对象/ 2.
        const url = new URL(currentURL);
        //3.获取查询参数
        const params = new URLSearchParams(url.search);
        //4.提取单个参数
        const id = params.get('id');//输出:'value1constparam1
        var title = $("#title").val();
        var author = $("#author").val();
        var time = $("#time").val();    
        $.post(`http://127.0.0.1:8000/items/update/${id}/${title}/${author}/${time}`, function(data, status) {
                alert("修改成功");

            })
              
        })
        $("#export_submit").on("click", function(e){
            var query = $("#query_input").val();
            $.get(`http://127.0.0.1:8000/items/export/${query}`, function(data, status) {
                alert("导出成功");
            })
        })
    })



function addRow1(id, title, author,time,create_time,creator,status) {
    var table = document.getElementById("book_table");
    var newRow = table.insertRow(-1); // 在表格末尾添加新行
    var cell1 = newRow.insertCell(0); // 在新行中插入第一个单元格
    var cell2 = newRow.insertCell(1); // 在新行中插入第二个单元格
    var cell3 = newRow.insertCell(2); // 在新行中插入第三个单元格
    var cell4 = newRow.insertCell(3); // 在新行中插入第一个单元格
    var cell5 = newRow.insertCell(4); // 在新行中插入第二个单元格
    var cell6 = newRow.insertCell(5); // 在新行中插入第三个单元格
    var cell7 = newRow.insertCell(6);
    cell1.textContent = id; // 设置单元格内容
    cell2.textContent = title;
    cell3.textContent = author;
    cell4.textContent = time; // 设置单元格内容
    cell5.textContent = create_time;
    cell6.textContent = creator;
    cell7.textContent = status;
}

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
    var cell9 = newRow.insertCell(8);
    var cell10 = newRow.insertCell(9);
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
    cell9.innerHTML = "<button onclick='update(" + id + ")'>修改</button>"; // 设置单元格内容;
    cell10.innerHTML = `<button onclick='delet(${id})'>删除</button>`; // 设置单元格内容;
}

function update(id) {
    location.href = "update.html?id=" + id;
}

    

function delet(id) {
    if(confirm("你确定要删除这本书吗?")){
        // 用户点击了“确定”
        console.log("User confirmed.");
        $.post("http://127.0.0.1:8000/items/delete/" + id, function(data, status) {
            alert("删除成功");
        });
    }else {
        // 用户点击了“取消”
        console.log("User cancelled.");
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