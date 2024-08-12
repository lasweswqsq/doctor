function downloadFile(url) {
    fetch(url)
        .then(response => {
            const reader = response.body.getReader();
            const stream = new ReadableStream({
                start(controller) {
                    function push() {
                        reader.read().then(({ done, value }) => {
                            if (done) {
                                controller.close();
                                return;
                            }
                            controller.enqueue(value);
                            push();
                        });
                    }
                    push();
                }
            });
            const blob = new Blob([stream], { type: response.headers.get('Content-Type') });
            const link = document.createElement('a');
            // 设置下载链接的href属性并模拟点击下载
            link.href = URL.createObjectURL(blob);
            link.download = 'myfile.txt'; // 设置下载的文件名
            link.click(); // 模拟点击下载
        })
    }
