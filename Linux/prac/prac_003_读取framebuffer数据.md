[TOC]

---
# 读取framebuffer数据

## framebuffer的IO操作
1. 第一个实践中我们用命令cat获得了framebuffer中的数据
2. 我们也可以利用系统调用函数，以代码的方式来读取并保存framebuffer的数据
3. 完成fb_read.c中的TODO
4. IO系统调用可以参考 [Linux系统应用第8章](http://mooc1.chaoxing.com/mooc-ans/nodedetailcontroller/visitnodedetail?courseId=223267590&knowledgeId=566249116)
5. 编译 `gcc fb_read.c -o fb_read`
6. 运行 `sudo ./fb_read c_screen.raw` 
7. 查看保存的c_screen.raw文件大小，必须和之前的screen.raw一致 
8. 可以参考第第一个实践，利用ffmpeg 把 c_screen.raw 文件转换成 png 文件，看看实际的图像 
 
## 小结
1. open * 2
2. ioctl -> fb_var_screeninfo
3. read 
4. write
5. close * 2