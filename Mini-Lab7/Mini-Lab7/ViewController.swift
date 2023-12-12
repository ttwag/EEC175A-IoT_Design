//
//  ViewController.swift
//  Mini-Lab7
//
//  Created by ttwag on 12/6/23.
//

import UIKit

class ViewController: UIViewController {
    var image_state = true
    private let imageView: UIImageView = {
        let imageView = UIImageView()
        imageView.contentMode = .scaleAspectFill
        imageView.backgroundColor = .white //set background color
        return imageView
    }()
    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = .systemPink
        view.addSubview(imageView)
        //Q1: Explain the rest of the code.
        imageView.frame = CGRect(x: 0, y: 0, width: 300, height: 300)
        imageView.center = view.center
        getPhoto()
        
        let changeImageButton = UIButton(type: .system)
        changeImageButton.setTitle("Change Image", for: .normal)
        changeImageButton.addTarget(self, action: #selector(changeImage), for: .touchUpInside)
        changeImageButton.backgroundColor = .white
        changeImageButton.setTitleColor(.black, for: .normal)
        changeImageButton.frame =  CGRect(
            x: 20,
            y: view.frame.size.height-90-view.safeAreaInsets.bottom,
            width: view.frame.size.width-40,
            height: 30
            )
        view.addSubview(changeImageButton)
    }
    func getPhoto() {
        imageView.image = UIImage(named: "Image1")
    }
    @objc func changeImage() {
        // Change the image here
        if (image_state) {
            imageView.image = UIImage(named: "Image2") // Change to Image2
        }
        else {
            imageView.image = UIImage(named: "Image1") // Change to Image1
        }
        image_state.toggle()
    }

}

