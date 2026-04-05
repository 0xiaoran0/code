import torch
from torch import nn
from torch.nn import Conv2d, ReLU, MaxPool2d, Sequential, Linear, Softmax, Flatten


class Guoer(nn.Module):
    def __init__(self) -> None:
        super().__init__()
        self.conv1 = Conv2d(1, 1, kernel_size=3, stride=1, bias=False)
        self.conv1.weight.data = torch.tensor([[[
            [0, 1, 2],
            [2, 2, 0],
            [0, 1, 2]
        ]]], dtype=torch.float)

        self.relu = ReLU()
        self.pool = MaxPool2d(kernel_size=2, stride=2, padding=1)
        self.flatten = Flatten()
        self.line = Linear(in_features=4, out_features=2, bias=True)
        self.line.weight.data = torch.tensor([
            [1, 0, 1, 0],
            [0, 1, 0, 1]
        ], dtype=torch.float)
        self.line.bias.data = torch.tensor([
            [1, 2]
        ], dtype=torch.float)

        self.softmax = nn.Softmax()

    def forward(self, x):
        x = self.conv1(x)

        x = self.relu(x)

        x = self.pool(x)

        x = self.flatten(x)

        x = self.line(x)

        x = self.softmax(x)

        return x

if __name__ == "__main__":
    model = Guoer()
    input = torch.tensor([
        [3, 3, 2, 1, 0],
        [0, 0, 1, 3, 1],
        [3, 1, 2, 2, 3],
        [2, 0, 0, 2, 2],
        [2, 0, 0, 0, 1]
    ], dtype=torch.float)
    input = torch.reshape(input, (1, 1, 5, 5))
    output = model(input)
    print(output)