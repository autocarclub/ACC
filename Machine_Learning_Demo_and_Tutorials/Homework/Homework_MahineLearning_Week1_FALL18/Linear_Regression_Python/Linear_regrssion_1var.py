import numpy as np
import matplotlib.pyplot as plt

# generate data
def random_y_create(x):
    return 3*x - 8 + 10*np.random.random()

def generate_data():
    list_x = np.arange(1,10, step= 0.5)
    list_y = []

    for x in list_x:
        y = random_y_create(x)
        list_y.append(y)

    return list_x, list_y

def plot_data(list_x, list_y):
    plt.scatter(list_x, list_y)
    plt.show()


def hx(x, a0, a1):
    #=========== Your Code Here ==============
    return 0   # change this line to return prediction value of y, given x


def cost( list_x, list_y, a0, a1):
    sum = 0.0

    # Compute cost (mean square error over all training set
    # =========== Your Code Here ==============


    # =========================================
    return sum


def gradients(list_x, list_y, a0, a1):
    grad_a0 = 0.0
    grad_a1 = 0.0

    # Compute gradient of cost function with respect to a0 and a1
    # =========== Your Code Here ==============


    # =========================================

    return grad_a0, grad_a1


def train(list_x, list_y, a0_init, a1_init):

    a0 = a0_init
    a1 = a1_init

    n_iterations = 10000
    learning_rate = 0.001

    for i in range(n_iterations):

        # compute cost in this iteration
        cost_i = cost(list_x, list_y, a0, a1)

        # get the gradients of cost funtion with respect to a0 and a1
        grad_a0, grad_a1 = gradients(list_x, list_y, a0, a1)

        # update value of a0 and a1
        # =========== Your Code Here ==============


        # =========================================

        if(i % 1000 == 0):
            print('cost at iteration', i ,':' ,cost_i)

    return a0, a1


# plot predict line
def plot_line(x, y):
    plt.plot(x, y, 'r')


def main():
    # create sample data
    list_x, list_y = generate_data()
    plot_data(list_x, list_y)

    # ===================  train linear regression  ========================
    # suppose fit a line y = a0 + a1*x through training data

    # initialize a0, a1
    a0_init = np.random.random()
    a1_init = np.random.random()

    #print(a0_init,a1_init)


    # get after-trained a0, a1
    a0, a1 = train(list_x, list_y, a0_init, a1_init)

    # predict y with training value of x
    list_y_predict = []
    for x in list_x:
        y_predict = hx(x, a0, a1)
        list_y_predict.append(y_predict)

    # plot data and see something fun
    plot_line(list_x, list_y_predict)
    plot_data(list_x, list_y)



main()
