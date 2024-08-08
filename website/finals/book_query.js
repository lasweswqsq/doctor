window.alert('welcome to this library management system');
$(function(){
    $("#query_submit").on("click", function(e){
        var query = $("#query_input").val();
        $.get("http://127.0.0.1:8000/items/" + query,function(data,status){
            //        IP        端口号
            //请求了"http://127.0.0.1:8000/items/" + query的地址
            alert("数据: " + data + "\n状态: " + status);

            $("query_submit").click(function(){
                $("book_table").append(data);
              });
            });
          });

    })





fetch('/query_db?query=SELECT%20*%20FROM%20book')
  .then(response => response.json())
  .then(data => {
    console.log(data);
    // 处理数据库返回的结果
  })
  .catch(error => console.error('Error:', error));

