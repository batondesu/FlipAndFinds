# Flip And Find

## IDE/Compiler 
 + CodeBlocks 20.03
## Thư viện
 + SDL-2.0.20  
 + SDL-Image-2.0.5  
 + SDL-Mixer-2.0.4  
 + SDL-TTF-2.012

## Game
### 1. Mô tả
   Ghi nhớ và chọn các cặp hình giống nhau trong thời gian ngắn nhất
### 2. Hướng dẫn
+ Mỗi lượt click chuột vào 2 ô hình đang bị ẩn. Sau đó, hình ảnh sẽ hiện ra để ghi nhớ.
+ Nếu 2 ảnh giống nhau, nó sẽ tự biến mất và ngược lại ảnh đó sẽ bị ẩn đi và ta cần ghi nhớ 2 ô đó.
+ Trong thời gian ngắn nhất, hãy làm biến mất tất cả các ô hình và tạo kỷ lục mới.
+ Game có 3 màn, mỗi màn sau độ khó sẽ tăng dần cần khả năng ghi nhớ cao.

## Algorithm
### 1. Hình ảnh
Ta sử dụng 1 vector lữu trữ link-ảnh. Sau đó sử dụng hàm Shuffle để in ngẫu nhiên các ảnh lên màn hình chơi với 1 tọa độ {x , y} và lưu các tọa độ trong 1 vector.
### 2. Thao tác
Mỗi lần click chuột: 
+ Kiểm tra và lấy tọa độ chuột.
+ Nếu khớp với tọa độ trong vector, hình ảnh tương ứng sẽ được lật lên.
+ Giới hạn mỗi lần 2 hình ảnh lật lên bằng 1 pair.
### 3. Xử lý
+ Check link-ảnh, Giống -> ảnh biến mất và ngược lại Khác -> ẩn lại.
+ Lặp lại cho đến khi không còn ảnh -> ghi nhận thời gian chơi và về màn hình chính.

## Kết luận và nhận xét
1. Game với thuật toán đơn giản, dễ hiểu, dễ triển khai và debug.
2. Có thể phát triển Game thêm: 
    * Hiệu ứng lật ảnh, chuyển tiếp Level 
    * Âm thanh mỗi lần click
    * Tăng thêm Level, phong phú chủ đề ảnh
    * Thêm gợi ý, cách chơi
    *  . . .   
3. Sau khi hoàn thiện chương trình giúp tăng khả năng code, có kiến thức nền tảng cơ bản về lập trình game và xử lý hiệu ứng...
