$(function(){
    $("#query_submit").on("click", function(e){
        var query = $("#query_input").val();
        
    })
})


fetch('/query_db?query=SELECT%20*%20FROM%20book')
  .then(response => response.json())
  .then(data => {
    console.log(data);
    // 处理数据库返回的结果
  })
  .catch(error => console.error('Error:', error));

