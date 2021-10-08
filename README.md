# Data Augmentation com C++ and OpenCv

Projeto 1 da disciplina de Programação Orientada a Objetos

Neste projeto, criamos uma ferramenta de data augmentation em imagens. A entrada para o programa seria uma pasta com imagens e a saída seria a multiplicação dessas imagens com efeitos diferentes 

O objetivo foi auxiliar em tarefas que tem como seu fim ultimo a utilização dessas imagens em modelos de Deep Convolutional Networks.


## Exemplo de funcionamento:


Dado uma pasta que contenha apenas a imagem da Lena:

![lena](https://user-images.githubusercontent.com/62849389/136020547-178e6055-ab2b-4c84-8dfc-39a1f8e67c2c.jpg)

O usuário escolhe as opções de filtro que quer aplicar:

- Gaussian Blur
- Black and White
- Rotate 
- Canny 
- Mirror

E então...

![lena_blur](https://user-images.githubusercontent.com/62849389/136021429-b78da68e-152f-4785-803c-6abbf4d49738.jpg)
![lena_bw](https://user-images.githubusercontent.com/62849389/136021431-47168cf0-2cf4-452d-98b2-76d99ed697cc.jpg)
![lena_canny](https://user-images.githubusercontent.com/62849389/136021435-fa933a53-6842-437e-9f8e-80e7f7110ddc.jpg)
![lena_mirror](https://user-images.githubusercontent.com/62849389/136021437-c1d93670-0d47-4c2f-986d-5ca352255b4e.jpg)
![lena_rotate](https://user-images.githubusercontent.com/62849389/136021438-75a18047-b9a1-49ce-b445-0afcc24695bb.jpg)

---

Imagine que isso pode ser aplicado diversas vezes em um dataset muito maior... O usuário pode sair de uma imagem para milhares em minutos.
